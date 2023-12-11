class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> mp;
        for(auto i:arr) mp[i]++;
        for(auto i:mp){
            if(i.second>int(0.25*n)) return i.first;
        }
        return -1;
    }
};
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> mp;
        int mx=0;
        for(auto i:nums){ 
            mp[i]++;
            mx=max(mx,mp[i]);
        }
        vector<vector<int>> v;
        for(int i=0;i<mx;i++){
            vector<int> temp;
            for(auto &i:mp){
                if(i.second>0){
                    temp.push_back(i.first);
                    i.second--;
                }
            }
            v.push_back(temp);
        }   return v;
    }
};
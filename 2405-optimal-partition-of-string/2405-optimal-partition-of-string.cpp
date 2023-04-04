class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,int> mp;
        int cnt=0;
        for(auto i:s){
            if(mp.count(i)==1){
                cnt++;
                mp.clear();
            }
            mp[i]+=1;
        }
        return cnt+1;
    }
};
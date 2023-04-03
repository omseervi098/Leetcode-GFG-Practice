class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> mp;int mx=0;
        for(auto i:nums) {mp[i]++;mx=max(mx,mp[i]);}    
        vector<vector<int>> v;
        while(mx-->0){
            vector<int> temp;
            for(auto &j:mp){
                if(j.second>0){
                    temp.push_back(j.first);
                    j.second-=1;
                }
            }
            v.push_back(temp);
        }
        return v;
        
    }
};
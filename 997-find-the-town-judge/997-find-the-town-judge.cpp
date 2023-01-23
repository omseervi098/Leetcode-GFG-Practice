class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> list(n+1);
        if(trust.size()==0){
            if(n==1) return 1;
            else return -1;
        }
        unordered_map<int,int> mp;
        for(auto i:trust){
            list[i[0]].push_back(i[1]);
            mp[i[1]]++;
            // mp[i[0]]++;
        }
        for(auto i:mp){
            if(i.second==n-1){
                if(list[i.first].size()==0){
                    return i.first;
                }
            }
        }
        
        return -1;
    }
};
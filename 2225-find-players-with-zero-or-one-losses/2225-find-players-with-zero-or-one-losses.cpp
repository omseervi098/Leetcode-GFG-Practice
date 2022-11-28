class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> n;
        for(auto i:matches){
            n[i[1]]+=1;
        }
         vector<vector<int>> ans(2);
        for(auto i:matches){
            if(n.count(i[0])==0){
                n[i[0]]=2;
                ans[0].push_back(i[0]);
            }
            if(n.count(i[1])>0 and n[i[1]]==1){
                 n[i[1]]=2;
                 ans[1].push_back(i[1]);
            }
        }
        sort(ans[1].begin(),ans[1].end());
        sort(ans[0].begin(),ans[0].end());
        return ans;
    }
};
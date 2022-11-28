class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> m,n;
        for(auto i:matches){
            m[i[0]]+=1;
            n[i[1]]+=1;
        }
         vector<vector<int>> ans(2);
        for(auto i:m){
            if(n.count(i.first)==0){
                ans[0].push_back(i.first);
            }
        }
        
        for(auto i:n){
            if(i.second==1){
                ans[1].push_back(i.first);
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> v;
        map<int,vector<int>> mp;
        for(int i=0;i<mat.size();i++){
            int cnt=0;
            for(int j=0;j<mat[i].size();j++)
                if(mat[i][j]==1) cnt++;
            mp[cnt].push_back(i);
        }
        for(auto i:mp){
            for(auto j:i.second){
                if(k>0) {
                    v.push_back(j);
                    k--;
                }
            }
        }
        return v;
    }
};
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,pair<int,int>> mp;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                mp[mat[i][j]]={i,j};
            }
        }
        int n=mat.size(),m=mat[0].size();
        unordered_map<int,vector<int>> row,col;
        for(int i=0;i<arr.size();i++){
            auto [r,c]=mp[arr[i]];
            row[r].push_back(c);
            col[c].push_back(r);
            if(row[r].size()==m) return i;
            if(col[c].size()==n) return i;
        }
        return arr.size();
    }
};
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if(r*c!=mat.size()*mat[0].size()||r==mat.size()&&c==mat[0].size())
            return mat;
        int current=0;
        vector<vector<int>>fmat(r,vector<int>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++)
            {
                int x=current/mat[0].size();
                int y=current%mat[0].size();
                fmat[i][j]=mat[x][y];
                current++;
            }
        }
        return fmat;
    }
};
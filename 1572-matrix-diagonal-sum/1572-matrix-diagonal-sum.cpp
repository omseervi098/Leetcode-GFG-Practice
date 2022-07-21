class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum=0;
    
        for(int i=0;i<mat.size();i++){
                int n=mat[i].size();
            for(int j=0;j<n;j++){
                if(i==j||i==n-1-j)
                {
                    sum+=mat[i][j];
                }
            }
        }return sum;
    }
};
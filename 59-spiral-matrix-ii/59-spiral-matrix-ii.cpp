class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int cnt=1;
        vector<vector<int>> mat(n,vector<int>(n));
        int rows=0,rowe=n-1,cols=0,cole=n-1;
        while(rows<=rowe && cols<=cole){
            for(int i=cols;i<=cole;i++){
                mat[rows][i]=cnt++;
            }rows++;
            for(int i=rows;i<=rowe;i++){
                mat[i][cole]=cnt++;
            }cole--;
            for(int i=cole;i>=cols;i--){
                mat[rowe][i]=cnt++;
            }rowe--;
            for(int i=rowe;i>=rows;i--){
                mat[i][cols]=cnt++;
            }cols++;
        }
        return mat;
    }
};
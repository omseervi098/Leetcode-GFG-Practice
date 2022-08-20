class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int cnt=0;
        int rows=matrix.size()-1;
        int cols=matrix[0].size()-1;
        int r=0,c=0;
        vector<int> v;
        int n=rows+1,m=cols+1;
        while(cnt<n*m){
            for(int i=c;i<=cols;i++){
                if(cnt==n*m) break;
                v.push_back(matrix[r][i]);cnt++;
            }
            r++;
            for(int i=r;i<=rows;i++){
                if(cnt==n*m) break;
                v.push_back(matrix[i][cols]);cnt++;
            }cols--;
            
            for(int i=cols;i>=c;i--){
                if(cnt==n*m) break;
                v.push_back(matrix[rows][i]);cnt++;
            }
            rows--;
            for(int i=rows;i>=r;i--){
                if(cnt==n*m) break;
                v.push_back(matrix[i][c]);cnt++;
            }c++;
            
        }return v;
    }
};
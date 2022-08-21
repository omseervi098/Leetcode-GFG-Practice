class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        unordered_set<int> s;
        unordered_set<int> s1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    s.insert(i);
                    s1.insert(j);   
                }
            }
        } 
        for(auto it:s){
            cout<<it<<endl;
            for(int i=0;i<n;i++){
                matrix[it][i]=0;
            }
        }
        for(auto it:s1){
            for(int i=0;i<m;i++){
                matrix[i][it]=0;
            }
        }
        return;
    }
};
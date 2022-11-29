class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<int> zeros,ones;
        for(int i=0;i<grid.size();i++){
            int one=0,zero=0;
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    one++;
                }else if(grid[i][j]==0){
                    zero++;
                }
            }
            zeros.push_back(zero);
            ones.push_back(one);
        }
        vector<int> zero1,one1;
        for(int i=0;i<grid[0].size();i++){
            int one=0,zero=0;
            for(int j=0;j<grid.size();j++){
                if(grid[j][i]==1){
                    one++;
                }else if(grid[j][i]==0){
                    zero++;
                }
            }
            zero1.push_back(zero);
            one1.push_back(one);
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                grid[i][j]=one1[j]+ones[i]-zero1[j]-zeros[i];
            }
        }
        return grid;
    }
};
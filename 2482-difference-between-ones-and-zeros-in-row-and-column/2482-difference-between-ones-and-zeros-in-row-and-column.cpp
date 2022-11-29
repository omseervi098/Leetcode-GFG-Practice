class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<int> ones;
        for(int i=0;i<grid.size();i++){
            int one=0;
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    one++;
                }
            }
            ones.push_back(one);
        }
        vector<int> one1;
        for(int i=0;i<grid[0].size();i++){
            int one=0;
            for(int j=0;j<grid.size();j++){
                if(grid[j][i]==1){
                    one++;
                }
            }
            one1.push_back(one);
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                grid[i][j]=one1[j]+ones[i]-(grid[0].size()-one1[j])-(grid.size()-ones[i]);
            }
        }
        return grid;
    }
};
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int mx=0;//7*4--28
        int touchwall=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    mx+=1;
                    if(i!=0 and grid[i-1][j]==1)touchwall++;
                    if(j!=0 and grid[i][j-1]==1) touchwall++;
                }
            }
        }
        return 4*mx-2*touchwall;
    }
};
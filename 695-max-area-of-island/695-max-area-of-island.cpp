class Solution {
public:
    int dfs(vector<vector<int>> &grid,int row,int col){
        if(row>=grid.size()||row<0 ||col>=grid[row].size()||col<0||grid[row][col]==0)
            return 0;
        grid[row][col]=0;
        return 1+dfs(grid,row-1,col)+dfs(grid,row+1,col)+dfs(grid,row,col-1)+dfs(grid,row,col+1);
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int mx=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    int sum=dfs(grid,i,j);
                    mx=max(mx,sum);
                }
            }
        }
        return mx;
    }
};
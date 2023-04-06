class Solution {
public:
    
    bool dfs(vector<vector<int>> &grid,int row,int col){
        if(row>=grid.size()||row<0 ||col>=grid[row].size()||col<0)
            return 0;
        if(grid[row][col]==1) return 1;
        grid[row][col]=1;
        bool a=dfs(grid,row-1,col);
        bool b=dfs(grid,row+1,col);
        bool c=dfs(grid,row,col-1);
        bool d=dfs(grid,row,col+1);
        return a && b && c && d;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int mx=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==0){
                    int sum=dfs(grid,i,j);
                    if(sum)
                        mx++;
                }
            }
        }
        return mx;
    }
};
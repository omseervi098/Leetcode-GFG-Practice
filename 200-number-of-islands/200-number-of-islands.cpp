class Solution {
public:
    int dfs(vector<vector<char>> &grid,int row,int col){
        if(row>=grid.size()||row<0 ||col>=grid[row].size()||col<0||grid[row][col]=='0')
            return 0;
        grid[row][col]='0';
        return 1+dfs(grid,row-1,col)+dfs(grid,row+1,col)+dfs(grid,row,col-1)+dfs(grid,row,col+1);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int mx=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1'){
                    int sum=dfs(grid,i,j);
                    if(sum>0)
                        mx++;
                }
            }
        }
        return mx;
    }
};
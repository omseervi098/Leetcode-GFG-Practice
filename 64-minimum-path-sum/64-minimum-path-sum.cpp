class Solution {
public:
    int dfs(vector<vector<int>> & grid,int x,int y,int m,int n,vector<vector<int>> &visited){
        if(x<0||y<0||x==m||y==n)
            return INT_MAX;
        //cout<<x<<" "<<y<<endl;
        if(x==m-1 and y==n-1)
            return grid[x][y];
        if(visited[x][y]!=-1) return visited[x][y];
        int down=dfs(grid,x+1,y,m,n,visited);
        if(down!=INT_MAX)
            down+=grid[x][y];
        int right=dfs(grid,x,y+1,m,n,visited);
        if(right!=INT_MAX)
            right+=grid[x][y];
        visited[x][y]=min(down,right);
        return visited[x][y];
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),-1));
        return dfs(grid,0,0,grid.size(),grid[0].size(),visited);
    }
};
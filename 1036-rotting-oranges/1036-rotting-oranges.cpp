class Solution {
public:
    void dfs(vector<vector<int>> & grid,int st,int end,int m,int n,int time=2){
        if(st<0 || end <0 || st>=m || end>=n || grid[st][end]==0 || 1<grid[st][end] && grid[st][end]<time){
            return;
        }
        grid[st][end]=time;
        dfs(grid,st-1,end,m,n,time+1);
        dfs(grid,st+1,end,m,n,time+1);
        dfs(grid,st,end-1,m,n,time+1);
        dfs(grid,st,end+1,m,n,time+1);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int ans=0,m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    dfs(grid,i,j,m,n);
                }
            }
        }
        int mn=2;
        for(auto &i:grid){
            for(auto j:i){
                cout<<j<<" ";
                if(j==1) return -1;
                mn=max(mn,j);
            }
            cout<<endl;
        }cout<<endl;
        return mn-2;
    }
};
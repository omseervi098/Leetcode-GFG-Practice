class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),tm=0,fresh=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }else if( grid[i][j]==1) fresh++;
            }
        }
        vector<pair<int,int>> dir={{-1,0},{0,1},{1,0},{0,-1}};
        while(q.size()){
            auto [co,t]=q.front();q.pop();
            int r=co.first,c=co.second;
            tm=max(t,tm);
            for(auto [dr,dc]:dir){
                int newr=dr+r;
                int newc=dc+c;
                if(newr>=0 && newc>=0 && newr<n and newc<m and vis[newr][newc]==0 && grid[newr][newc]==1){
                    q.push({{newr,newc},t+1});
                    vis[newr][newc]=2;
                    fresh--;
                }
            }
        }
        if(fresh>0) return -1;
        return tm;
    }
};
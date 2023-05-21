class Solution {
public:

    bool isValid(int i,int j,int n,int m){
        return i>=0 && j>=0 && i<n && j<m ; 
    }

    void bfs(int i,int j,vector<vector<int>> &grid,
        vector<vector<int>> &vis,vector<pair<int,int>> &island1,
            vector<pair<int,int>> &island2,bool &flag){
        int n = grid.size() , m = grid[0].size() ; 
        queue<pair<int,int>> q ;  q.push({i,j}) ;
        if(flag) island1.push_back({i,j}) ;
        else island2.push_back({i,j}) ;
        vis[i][j] = 1 ;

        int delx[] = {-1,0,+1,0} ;
        int dely[] = {0,+1,0,-1} ; 

        while(!q.empty()){
            auto knnc = q.front() ; q.pop() ;
            int x = knnc.first ; 
            int y = knnc.second ; 
            for(int i1=0 ; i1<4 ; i1++){
                int newx = x + delx[i1] ;
                int newy = y + dely[i1] ; 
                if(isValid(newx,newy,n,m) && 
                    grid[newx][newy] == 1 && 
                        vis[newx][newy] == 0){
                    vis[newx][newy] = 1 ;
                    q.push({newx,newy}) ;
                    if(flag) island1.push_back({newx,newy}) ;
                    else island2.push_back({newx,newy}) ;  
                }
            }
        }

        if(flag) flag = !flag ; 
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size() ; 
        vector<pair<int,int>> island1 , island2 ; 
        vector<vector<int>> vis(n,vector<int> (m,0)) ;
        bool flag = true ;  
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(vis[i][j] == 0 && grid[i][j] == 1){
                    bfs(i,j,grid,vis,island1,island2,flag) ; 
                }
            }
        } 
        int ans = 1e9 , size1 = island1.size() ;
        int size2 = island2.size() ;  
        for(int i=0 ; i<size1 ; i++){
            for(int j=0 ; j<size2 ; j++){
                ans = min(ans , 
                    abs(island1[i].first - island2[j].first) + 
                    abs(island1[i].second - island2[j].second) - 1) ;
            }
        }

        return ans ; 
    }
};
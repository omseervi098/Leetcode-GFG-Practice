class Solution {
    void bfs(int sr,int sc,int n,int m,int ncol,vector<vector<int>> &i,vector<vector<int>> &vis){
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int oldcolor=i[sr][sc];
        i[sr][sc]=ncol;
        vis[sr][sc]=1;
        vector<pair<int,int>> dir={{-1,0},{0,1},{1,0},{0,-1}};
        while(q.size()){
            auto front=q.front();q.pop();
            
            for(auto [dr,dc]:dir){
                    int newr=front.first+dr;
                    int newc=front.second+dc;
                    if(newr>=0 && newc>=0 && newr<n && newc<m && vis[newr][newc]!=1 && i[newr][newc]==oldcolor){
                        q.push({newr,newc});
                        vis[newr][newc]=1;
                        i[newr][newc]=ncol;
                    }
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size(),m=image[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        bfs(sr,sc,n,m,color,image,visited);
        return image;
    }
};
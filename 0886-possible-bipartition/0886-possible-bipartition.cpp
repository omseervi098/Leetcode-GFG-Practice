class Solution {
public:
    bool dfs(vector<vector<int>> &adj,vector<int> &vis,int st,int col){
        vis[st]=col;
        for(auto i:adj[st]){
            if(vis[i]==-1){
                vis[i]=!col;
                if(dfs(adj,vis,i,!col)==false) return false;
            }else if(vis[i]==vis[st]){
                return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        vector<int> vis(n+1,-1);
        for(auto i:dislikes){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(int i=1;i<=n;i++){
            if(vis[i]==-1){
                if(dfs(adj,vis,i,0)==false) return false;
            }
        }
        return true;
    }
};
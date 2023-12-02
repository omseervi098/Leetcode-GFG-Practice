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
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(),-1);
         for(int i=0;i<graph.size();i++){
            if(vis[i]==-1){
                if(dfs(graph,vis,i,0)==false) return false;
            }
        }
        return true;
    }
};
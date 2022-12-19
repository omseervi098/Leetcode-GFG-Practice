class Solution {
public:
    bool hasPath(vector<vector<int>> &graph,int n,int a,int b,vector<bool> &vis){
        if(a==b){
            return true;
        }
        vis[a]=true;
        for(auto i:graph[a]){
            if(!vis[i]){
                if(hasPath(graph,n,i,b,vis)) return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for(auto i:edges){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        
        vector<bool> visited(n,false);
        return hasPath(graph,n,source,destination,visited);
    }
};
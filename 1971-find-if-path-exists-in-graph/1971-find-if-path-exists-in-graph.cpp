class Solution {
     
public:
    bool hasPath(unordered_map<int, vector<int>> &graph,int n,int a,int b,vector<bool> &vis){
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
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < edges.size(); i++){
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n,false);
        return hasPath(mp,n,source,destination,visited);
    }
};
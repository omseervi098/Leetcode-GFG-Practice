class Solution {
public:
    int dfs(vector<vector<int>> &adj,vector<bool>&has,int st,int parent,int dist){
        int distfromchild=0,distfromroot=0;
        for(auto i:adj[st]){
            if(i!=parent){
                distfromroot=dfs(adj,has,i,st,dist+1);
                if(distfromroot!=0)distfromchild+=distfromroot-dist;   
            }
        }return distfromchild || has[st]?distfromchild+dist:0;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        return dfs(adj,hasApple,0,-1,0)*2;
    }
};
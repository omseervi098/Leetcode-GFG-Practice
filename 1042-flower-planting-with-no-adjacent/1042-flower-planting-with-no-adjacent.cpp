class Solution {
    void bfs(int st,vector<vector<int>> &adj,vector<bool> &vis,int cnt,vector<int> &v){
        queue<int> q;
        q.push(st);
        vis[st]=1;
        v[st-1]=1;
        while(q.size()){
            int front=q.front();q.pop();
            vector<bool> temp(5,false);
            for(auto i:adj[front]){
                if(vis[i]){
                    for(int j=1;j<=4;j++)
                        if(v[i-1]==j) temp[j]=true;
                    continue;
                }
                q.push(i);
                vis[i]=1;
            }
            for(int i=1;i<=4;i++) if(!temp[i]) v[front-1]=i;
        }
    }
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n+1);
        for(auto i:paths){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<bool> visited(n+1,false);
        vector<int> v(n,-1);
        for(int i=1;i<=n;i++){
            if(!visited[i])
                bfs(i,adj,visited,1,v);
        }
        return v;
    }
};
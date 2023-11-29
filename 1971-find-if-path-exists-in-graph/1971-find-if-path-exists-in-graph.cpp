class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        queue<int> q;
        vector<bool> visited(n);
        q.push(source);
        visited[source]=1;
        while(q.size()){
            int front=q.front();
            if(front==destination) return true;
            q.pop();
            for(auto i:adj[front]){
                if(visited[i]) continue;
                q.push(i);
                visited[i]=1;
            }
        }
        return false;
    }
};
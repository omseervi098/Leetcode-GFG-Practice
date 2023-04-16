class Graph {
    int n;
    vector<vector<pair<int, int>>> adj;
    int helper(int src, int dest)
    {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (u == dest) return d;
            if (d > dist[u]) continue;
            for (auto [v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return -1;
    }

    public:
    Graph(int n, vector<vector<int>>& edges) {
        this->n=n;
        adj.resize(n);
        for(auto &i:edges){
            adj[i[0]].emplace_back(i[1],i[2]);
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].emplace_back(edge[1],edge[2]);
    }
    
    int shortestPath(int node1, int node2) {
        return helper(node1,node2);
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
class Solution {
     
public:
    
    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < edges.size(); i++){
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> vis(n,false);
        queue<int> q;
        q.push(s);
        vis[s]=true;
        while(q.size()){
            int i=q.front();q.pop();
            if(i==d) return true;
            for(auto j:mp[i])
            {
                if(!vis[j]){
                    q.push(j);
                    vis[j]=true;
                }
            }        
        }return false;
    }
};
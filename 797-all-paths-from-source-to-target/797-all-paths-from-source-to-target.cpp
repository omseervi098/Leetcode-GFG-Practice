class Solution{
    vector<vector<int>> res;
    vector<int> tmp;
    public:
    void dfs(vector<vector<int>> &graph,int curr,int targ){
        tmp.push_back(curr);
        if(curr==targ) res.push_back(tmp);
        else{
        for(auto i:graph[curr])
            dfs(graph,i,targ);
        }
        tmp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(graph,0,graph.size()-1);
        return res;
    }
};
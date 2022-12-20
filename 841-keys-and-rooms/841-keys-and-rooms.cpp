class Solution {
public:
    void dfs(vector<vector<int>>& rooms,int st,vector<int> &vis){
        if(st==rooms.size()){
            return;
        }
        vis[st]=true;
        for(auto i:rooms[st]){
            if(vis[i]!=true){
                dfs(rooms,i,vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> vis(rooms.size(),false);
        dfs(rooms,0,vis);
        for(auto i:vis) {
            if(i==false) return false;
        }
        return true;
    }
};
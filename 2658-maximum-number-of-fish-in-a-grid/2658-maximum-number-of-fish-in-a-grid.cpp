class Solution {
public:
    int bfs(vector<vector<int>>& grid, int i, int j,vector<vector<bool>> &visited) {
        queue<pair<int, int>> q;
        int mx=0;
        q.push({i,j});
        visited[i][j] = true;
        int fishCount = grid[i][j];
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        while (!q.empty()) {
            auto [r,c]=q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int ni = r + dx[k], nj = c + dy[k];
                if (ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[0].size() && grid[ni][nj] > 0 && !visited[ni][nj]) {
                    q.push({ni, nj});
                    visited[ni][nj] = true;
                    fishCount += grid[ni][nj];
                }
            }
        }

        return fishCount;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int mx=0;
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        for (int i = 0; i < grid.size();i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] > 0 and !visited[i][j]){
                    mx=max(mx,bfs(grid, i, j,visited));
                }
            }
        }
        return mx;
    }
};
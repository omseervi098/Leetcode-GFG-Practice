class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        int ans=0;
        for(auto &i:grid) sort(i.begin(),i.end());
        for(int i=0;i<c;i++){
            int mx=INT_MIN;
            for(int j=0;j<r;j++) mx=max(mx,grid[j][i]);
            ans+=mx;   
        }
        return ans;
    }
};
class Solution {
public:
    int helper(vector<vector<int>> &tri,int row,int size,int i, vector<vector<int>>& dp){
        if(row==size){
            return 0;
        }
        if(dp[row][i]!=-999999)
            return dp[row][i];
        int isum= tri[row][i]+helper(tri,row+1,size,i,dp);
        int i1sum=tri[row][i]+helper(tri,row+1,size,i+1,dp);
        dp[row][i]=min(isum,i1sum);
        return dp[row][i];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp(triangle.size(),vector<int>(triangle.size(),-999999));
        return helper(triangle,0,triangle.size(),0,dp);
    }
};
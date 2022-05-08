// Problem No. 931 Min. falling Fath sum
// Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
// Output: 13
//Using Memoization in O(N^2)
class Solution {
public:
    int helper(vector<vector<int>>&matrix,int row,int col,vector<vector<int>> &dp){
        if(col>=matrix.size()||col<0){
            return 10000000;
        }if(row==matrix.size()-1)
            return matrix[matrix.size()-1][col];
        if(dp[row][col]!=-1)
            return dp[row][col];
        int ans=10000000;
         int x=matrix[row][col]+helper(matrix,row+1,col-1,dp);
         int y=matrix[row][col]+helper(matrix,row+1,col,dp);
          int z=matrix[row][col]+helper(matrix,row+1,col+1,dp);
          ans=min(ans,(min(x,min(y,z))));
        dp[row][col]=ans;
        return ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX;
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix.size()));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix.size();j++)
                dp[i][j]=-1;
        }
        for(int i=0;i<matrix.size();i++){
            int temp=helper(matrix,0,i,dp);
            ans=min(ans,temp);
        }
        return ans;
    }
};
//Using Tabulation 
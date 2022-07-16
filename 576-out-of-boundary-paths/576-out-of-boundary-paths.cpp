
class Solution {
public:
    int dp[55][55][55];
    long long mod = 1e9 + 7;
    int helper(int m,int n,int max,int i,int j){
        if(max<0)
            return 0;
        if(i==m||j==n||i==-1||j==-1) return 1;
        if(dp[i][j][max]!=-1) return dp[i][j][max];
        int  ans=((helper(m,n,max-1,i-1,j)%mod)+(helper(m,n,max-1,i+1,j)%mod)+(helper(m,n,max-1,i,j-1)%mod)+(helper(m,n,max-1,i,j+1)%mod))%mod;
        dp[i][j][max]=ans;
        return ans;
        
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)     {
          memset(dp, -1, sizeof(dp));
          return helper(m,n,maxMove,startRow,startColumn);
    }
};
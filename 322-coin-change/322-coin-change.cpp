class Solution {
public:
    int coinChange(vector<int>& deno, int amt) {
        int n=deno.size();
        int dp[n+1][amt+1];
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<=amt;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<=n;i++){
        int d=deno[i-1];
        for(int j=1;j<=amt;j++){
            if(i==1 && j<d)
                dp[i][j]=99999;
            else if(j<d)
                dp[i][j]=dp[i-1][j];
            else if(i==1)
                dp[i][j]=1+dp[i][j-d];
            else{
                if(dp[i-1][j]<1+dp[i][j-d]){
                    dp[i][j]=dp[i-1][j];
                }else{
                    dp[i][j]=1+dp[i][j-d];
                }
            }
        }
    }return dp[n][amt]>=99999?-1:dp[n][amt];
    }
};
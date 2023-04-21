class Solution {
    vector<vector<vector<long long>>> dp;
    const int mod=1e9+7;
public:
    long long helper(vector<int> &p,vector<int> &g,long long profit,int n,int st){
        if(n<0){
            return 0;
        }
        if(st>=p.size()){
            if(profit<=0) return 1;
            return 0;
        }
        if(profit<0) profit=0;
        if(dp[st][n][profit]!=-1) return dp[st][n][profit];
        //excluding
        int a=helper(p,g,profit,n,st+1)%mod;
        //including
        int b=helper(p,g,profit-p[st],n-g[st],st+1)%mod;
        return dp[st][n][profit]=(a+b)%mod;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        dp.resize(profit.size()+1,vector<vector<long long>>(n+1,vector<long long>(minProfit+1,-1)));
        return helper(profit,group,minProfit,n,0)%mod;
    }
};
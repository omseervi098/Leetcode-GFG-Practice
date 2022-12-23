class Solution {
public:
    int dfs(vector<int> &p,bool buy,int i,vector<vector<int>> &dp){
        if (i>=p.size()) return 0;
        if(dp[buy][i]!=-1) return dp[buy][i];
        int ans=0;
        if(!buy){
            int a=0;
            if(i<p.size())
                a=-p[i]+dfs(p,!buy,i+1,dp);//if buying
            int b=dfs(p,buy,i+1,dp);//not buying
            return dp[buy][i]=max(a,b);
        }
        if(buy){
            int a=0;
            if(i<p.size())
                a=p[i]+dfs(p,!buy,i+2,dp);//if selling 
            int b=dfs(p,buy,i+1,dp);//not selling
            return dp[buy][i]=max(a,b);
        }
        return 0;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(2,vector<int>(prices.size()+1,-1));
        return dfs(prices,false,0,dp);
    }
};
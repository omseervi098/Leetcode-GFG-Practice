#define ll long long
class Solution {
    const int mod=1e9+7;
public:
    ll helper(int low,int high,int temp,int zero,int one,vector<int> &dp){
        if(temp>high) return 0;
        if(dp[temp]!=-1) return dp[temp];
        ll ans=0;
        if(temp>=low and temp<=high) ans=1;
        int a=helper(low,high,temp+zero,zero,one,dp)%mod;
        int b=helper(low,high,temp+one,zero,one,dp)%mod;
        ans+=(a+b)%mod;
        return dp[temp]=ans;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(1000000,-1);
        return helper(low,high,0,zero,one,dp);
    }
};
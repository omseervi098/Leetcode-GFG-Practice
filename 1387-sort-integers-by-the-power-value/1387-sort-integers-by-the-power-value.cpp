class Solution {
    unordered_map<int,int> dp;
public:
    int helper(int x){
        if(dp[x]|| x==1) return dp[x];
        if(x&1) dp[x]=1+helper(3*x+1);
        else dp[x]=1+helper(x/2);
        return dp[x];
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> h;
        for(int i=lo;i<=hi;i++)
            h.push_back({helper(i),i});
        sort(h.begin(),h.end());
        return h[k-1].second;
    }
};
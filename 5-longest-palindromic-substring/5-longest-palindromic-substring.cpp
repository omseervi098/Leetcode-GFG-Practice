class Solution {
public:
    int l=0,r=0;
    int helper(string &s,int st,int end,vector<vector<int>> &dp){
        if(st>end) return 0;
        if(st==end) return 1;
        if(dp[st][end]!=-1)return dp[st][end];
        if(s[st]==s[end]){
            int size=end-st+1;
            int subans=helper(s,st+1,end-1,dp);
            if(size==2+subans)
            {
                if(end-st>r-l){
                   l=st;
                   r=end;
                }
                dp[st][end]=size;
                return size;
            }
        }
        dp[st][end]=max(helper(s,st+1,end,dp),helper(s,st,end-1,dp));
        return dp[st][end];
    }
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
        helper(s,0,n-1,dp);
        return s.substr(l,r-l+1);
    }
};
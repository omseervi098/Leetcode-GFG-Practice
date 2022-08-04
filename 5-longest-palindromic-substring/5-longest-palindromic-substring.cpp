class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
     vector<vector<int>> dp(n,vector<int>(n,0));
    int l=0,r=0;
    for(int i=n-1;i>=0;i--){
        for(int j=i;j<n;j++){
            if(i==j) dp[i][j]=1;
            else if(s[i]==s[j] and 2+dp[i+1][j-1]==(j-i+1))
            {
                if((j-i)>(r-l))
                {
                    l=i;r=j;
                }
                dp[i][j]=2+dp[i+1][j-1];
            }else
            dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
        }
    }
    return s.substr(l,r-l+1);
    }
};
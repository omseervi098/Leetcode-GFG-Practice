class Solution {
public:
    int helper(int n,string s,string t,vector<vector<int>> &dp){
        if(n==1) return t.size();
        int ans=0;
        if(dp[t.size()-1][n-1]!=-1)return dp[t.size()-1][n-1];
        for(int i=0;i<t.size();i++){
            //cout<<n<<" "<<s<<" "<<t<<" "<<ans<<endl;
            ans+=helper(n-1,s+t[i],t.substr(i),dp);
        }
        dp[t.size()-1][n-1]=ans;
        return ans;
    }
    int countVowelStrings(int n) {
        string t="aeiou";
        vector<vector<int>> dp(5,vector<int>(n,-1));
        return helper(n,"",t,dp);
    }
};
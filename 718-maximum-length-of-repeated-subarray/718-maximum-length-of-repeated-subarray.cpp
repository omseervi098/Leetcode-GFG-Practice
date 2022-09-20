class Solution {
    int mx=0;
public:
    int mrs(vector<int> &n1,vector<int> &n2,int i,int j,vector<vector<int>> &dp){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(n1[i]==n2[j]){
            ans=1+mrs(n1,n2,i-1,j-1,dp);
        }

        mx=max(mx,ans);
        return dp[i][j]=ans;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2)         {
        int n1=nums1.size(),n2=nums2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        int fans=0;
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    fans=max(fans,dp[i][j]);
                }
            }
        }
        return fans;
        return mx;
    }
};
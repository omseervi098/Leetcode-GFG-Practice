class Solution {
public:
    
    //Bruteforce O(n*2^n)
    int helper(vector<int> &nums,int prev_i,int st,vector<int> &dp){
        if(st>=nums.size())
        {
            //dp[st]=v.size();
            return 0;
        }
        if(dp[prev_i+1]!=-1) return dp[prev_i+1];
        int mx=0;
        
            if(prev_i==-1 || nums[st]>nums[prev_i]){
               int sans=1+helper(nums,st,st+1,dp);
               mx=max(mx,sans);
            }
                int dont=helper(nums,prev_i,st+1,dp);
               mx=max(mx,dont);
            
        dp[prev_i+1]=mx;
        return mx;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return helper(nums,-1,0,dp);
    }
};
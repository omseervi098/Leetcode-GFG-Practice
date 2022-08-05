class Solution {
public:
    int helper(vector<int> &nums,int target,int st,vector<vector<int>> &dp){
        if(st==nums.size()){
            if(target==0)
                return 1;
            return 0;
        }
        if(dp[st][target]!=-1) return dp[st][target];
        int exc=helper(nums,target,st+1,dp);
        int inc=0;
      
           if(target-nums[st]>=0)
              inc+=helper(nums,target-nums[st],st,dp); 
        dp[st][target]=inc+exc;
        return inc+exc;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
        return helper(coins,amount,0,dp);
    }
};
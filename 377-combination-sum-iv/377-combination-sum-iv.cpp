class Solution {
public:
    int helper(vector<int> &nums,int target,int st,vector<int> &dp){
       if(target==0)
                return 1;
        if(target<0) return 0;
        int inc=0;
        if(dp[target]!=-1) return dp[target];
        for(int i=0;i<nums.size();i++){
            if(target-nums[i]>=0)
                inc+=helper(nums,target-nums[i],i,dp); 
        }
        dp[target]=inc;
        return inc;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target+1,0);
        dp[0]=1;
        for(int i=1;i<=target;i++){
            
            for(int j=0;j<nums.size();j++){
                if(i>=nums[j]){
                    dp[i]=dp[i]+dp[i-nums[j]];
                }
            }
        }
        return dp[target];
    }
};
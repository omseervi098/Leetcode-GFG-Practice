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
        int n=nums.size();
        vector<int> v(target+1,-1);
        
        return helper(nums,target,0,v);
    }
};
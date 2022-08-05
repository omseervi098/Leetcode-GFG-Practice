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
    int change(int target, vector<int>& nums) {
       vector<int> dp(target+1,0);
        dp[0]=1;
        for(int i=0;i<nums.size();i++){
            
            for(int j=1;j<=target;j++){
                if(j>=nums[i]){
                    dp[j]=dp[j]+dp[j-nums[i]];
                }
            }
        }
        return dp[target];
    }
};
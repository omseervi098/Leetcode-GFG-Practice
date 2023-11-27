class Solution {
    vector<int> dp;
    int helper(vector<int> &arr,int st,int n){
        if(st>=n) return 0;
        if(dp[st]!=-1) return dp[st];
        return dp[st]=max(arr[st]+helper(arr,st+2,n),helper(arr,st+1,n));
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        dp.resize(nums.size(),-1);
        int a=helper(nums,0,nums.size()-1);
        for(auto &i:dp) i=-1;
        int b=helper(nums,1,nums.size());
        return max(a,b);
    }
};
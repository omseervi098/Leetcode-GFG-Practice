class Solution {
    vector<int> dp;
    int helper(vector<int> &arr,int st){
        if(st>=arr.size()) return 0;
        if(dp[st]!=-1) return dp[st];
        return dp[st]=max(arr[st]+helper(arr,st+2),helper(arr,st+1));
    }
public:
    int rob(vector<int>& nums) {
        dp.resize(nums.size(),-1);
        return helper(nums,0);
    }
};
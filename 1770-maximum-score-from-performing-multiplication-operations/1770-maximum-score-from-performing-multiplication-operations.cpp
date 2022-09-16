class Solution {
    vector<vector<int>> dp;
public:
    int helper(int st,int end,int idx,vector<int> &nums,vector<int> &mul){
        if(idx>=mul.size()){
            return 0;
        }
       
        if(dp[st][idx]!=INT_MIN) return dp[st][idx];
       
        return dp[st][idx]=max((nums[st]*mul[idx]+helper(st+1,end,idx+1,nums,mul)),(nums[end]*mul[idx]+helper(st,end-1,idx+1,nums,mul)));
        
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m=multipliers.size();
        dp.resize(m+1,vector<int>(m+1,INT_MIN));
        return helper(0,nums.size()-1,0,nums,multipliers);
    }
};
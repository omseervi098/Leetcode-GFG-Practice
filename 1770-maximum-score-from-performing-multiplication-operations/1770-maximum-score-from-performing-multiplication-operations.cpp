class Solution {
    vector<vector<int>> dp;
public:
    int helper(int st,int end,int idx,vector<int> &nums,vector<int> &mul){
        if(idx>=mul.size()){
            return 0;
        }
       
        if(dp[st][idx]!=INT_MIN) return dp[st][idx];
       
        return dp[st][idx]=max((nums[st]*mul[idx]+helper(st+1,end,idx+1,nums,mul)),(nums[nums.size()-(idx-st)-1]*mul[idx]+helper(st,end,idx+1,nums,mul)));
        
    }
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        int m=mul.size();
        dp.resize(m+1,vector<int>(m+1,0));
        for(int st=m-1;st>=0;st--){
            for(int idx=m-1;idx>=st;idx--){
                int e=nums.size()-(idx-st)-1;
                int start=nums[st]*mul[idx]+dp[st+1][idx+1];
                int end=nums[e]*mul[idx]+dp[st][idx+1];
                dp[st][idx]=max(start,end);
            }
        }
        return dp[0][0];
    }
};
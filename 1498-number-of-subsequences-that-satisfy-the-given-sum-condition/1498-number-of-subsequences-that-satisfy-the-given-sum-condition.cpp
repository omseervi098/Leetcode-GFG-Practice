class Solution {
public:
    int numSubseq(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long res = 0;
        int k = 1'000'000'007;
        vector<long> dp(n + 1, 1);
        for(int i = 1; i <= n; ++i)
        {
            dp[i] = (dp[i - 1] << 1) % k;
        }
        for(int i = 0, j = n - 1; i < n; ++i)
        {
            while(j >= i && nums[i] + nums[j] > target) 
            {
                --j;
            }
            if(i > j) 
            {
                continue;
            } 
            res = (res + dp[j - i]) % k; 
        }
        return res;
    }
};
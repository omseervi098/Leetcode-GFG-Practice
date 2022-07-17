class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        int mx=0;
        sort(nums.begin(), nums.end(), greater <>());
        for(int i=0;i<n-2;i++){
            if(nums[i]+nums[i+1]>nums[i+2] and nums[i+2]+nums[i+1]>nums[i] and nums[i]+nums[i+2]>nums[i+1])
                mx=max(mx,(nums[i]+nums[i+1]+nums[i+2]));
            }
        return mx;
    }
};
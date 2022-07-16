class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(auto &it:nums)
            it*=it;
        int low=0,high=nums.size()-1;
        vector<int> ans(nums.size());
        int k=nums.size()-1;
        while(low<=high){
            if(nums[low]<nums[high]){
                ans[k--]=nums[high];
                high--;
            }else if(nums[low]>=nums[high]){
                ans[k--]=nums[low++];
            }
        }
        return ans;
    }
};
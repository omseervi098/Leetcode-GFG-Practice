class Solution {
public:
    void permute(vector<int>& nums,int idx,vector<vector<int>>&v) {
        if(nums.size()==idx)
        {
            v.push_back(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++)
        {
            swap(nums[i],nums[idx]);
            permute(nums,idx+1,v);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> v;
        permute(nums,0,v);
        return v;
    }
};
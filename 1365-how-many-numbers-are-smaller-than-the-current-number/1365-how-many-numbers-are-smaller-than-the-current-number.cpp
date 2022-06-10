class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int bkt[102]{0};
        for(int i=0; i<nums.size(); i++) bkt[nums[i] + 1]++;
        for(int i=1; i<102; i++) bkt[i] += bkt[i-1];
        for(int i=0; i<nums.size(); i++) nums[i] = bkt[nums[i]];
        return nums;
    }
};
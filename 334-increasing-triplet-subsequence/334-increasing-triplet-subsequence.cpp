class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int mn1=INT_MAX;
        int mn1idx=0;
        int mn2=INT_MAX;
        int mn2idx=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<mn1){
                mn1=nums[i];
                mn1idx=i;
            }else if(nums[i]<mn2 and nums[i]>mn1 and i>mn1idx){
                mn2=nums[i];
                mn2idx=i;
            }else if(nums[i]>mn2 and i>mn2idx)
                return true;
        }return false;
    }
};
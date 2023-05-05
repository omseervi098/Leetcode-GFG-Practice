class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sm=accumulate(nums.begin(),nums.end(),0);
        int tmp=0;
        // if(sm==tmp)return 0;
        for(int i=0;i<nums.size();i++){
            sm-=nums[i];
            if(sm==tmp) return i;
            tmp+=nums[i];
        }
        return -1;
    
    }
};
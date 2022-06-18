class Solution {
public:
    void sortColors(vector<int>& nums) {
        int nzero=0,ntwo=nums.size()-1,curr=0;
        while(curr<=ntwo){
            if(nums[curr]==0){
                swap(nums[curr++],nums[nzero++]);
            }else if(nums[curr]==2)
                swap(nums[curr],nums[ntwo--]);
            else
                curr++;
        }
        
    }
};
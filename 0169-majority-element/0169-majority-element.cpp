class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=1,ele=nums[0];
        for(int i=1;i<nums.size();i++){
            if(cnt==0) ele=nums[i];
            if(nums[i]==ele) cnt++;
            else cnt--;
        }
        cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele) cnt++;
        }
        return cnt>=nums.size()/2?ele:-1;
    }
};
class Solution {
    int isvalid(vector<int> &nums,long long mid){
        long long sm=0;
        for(int i=0;i<nums.size();i++){
            sm+=nums[i];
            if(sm>(i+1)*mid){
                return false;
            }
        }
        return true;
    }
    public:
    int minimizeArrayValue(vector<int>& nums) {
        long long sm=0;int mx=0;
        for(int i=0;i<nums.size();i++){
            sm+=nums[i];
            int tmp=ceil(sm/double(i+1));
            mx=max(mx,tmp);
        }
        return mx;
    }
};
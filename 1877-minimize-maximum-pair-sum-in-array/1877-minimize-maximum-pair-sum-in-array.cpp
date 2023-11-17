class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int st=0,end=nums.size()-1;
        int mx=0;
        while(st<end){
            mx=max(mx,nums[st++]+nums[end--]);
        }
        return mx;
    }
};
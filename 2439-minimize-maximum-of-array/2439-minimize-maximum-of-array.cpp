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
        int mn=*min_element(nums.begin(),nums.end());
        int mx=*max_element(nums.begin(),nums.end());
        while(mn<=mx){
            long long mid=(mn+mx)/2;
            cout<<mid<<" ";
            if(isvalid(nums,mid)){
                mx=mid-1;
            }else{
                mn=mid+1;
            }
        }
        return mn;
    }
};
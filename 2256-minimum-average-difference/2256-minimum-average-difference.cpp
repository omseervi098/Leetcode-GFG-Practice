class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long sm=0;
        for(auto i:nums) sm+=i;
        long long pre=0,k=1,n=nums.size(),mn=INT_MAX,mnidx=0;
        for(int i=0;i<nums.size();i++){
            pre+=nums[i];
            int check=0;
            if(k<n) check=((sm-pre)/(n-k));
            int diff=abs((pre/k++)-check);
            if(diff<mn){
                mn=diff;
                mnidx=i;
            }
        }
        return mnidx;   
    }
};
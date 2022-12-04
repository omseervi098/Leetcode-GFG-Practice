class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long sm=0,pre=0,k=1,n=nums.size(),mn=INT_MAX,mnidx=0;
        for(auto i:nums) sm+=i;
        for(int i=0;i<nums.size();i++){
            pre+=nums[i];
            int diff=pre/k;
            if(k<n) diff=abs(pre/k-(sm-pre)/(n-k++));
            if(diff<mn){
                mn=diff;
                mnidx=i;
            }
        }
        return mnidx;   
    }
};
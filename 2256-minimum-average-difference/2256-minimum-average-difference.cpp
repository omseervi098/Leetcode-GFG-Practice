class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long sm=0,n=nums.size(),k=1,j=n,mn=INT_MAX,mnidx=0;
        vector<int> pre,suf(n+1);
        for(auto it:nums){
            sm+=it;
            pre.push_back(sm/k++);
        }
        suf[n--]=0;sm=0;k=1;
        for(int i=n;i>=0;i--){
            sm+=nums[i];
            suf[n--]=sm/k++;
        }
        for(int i=0;i<nums.size();i++){
            int diff=abs(pre[i]-suf[i+1]);
            if(diff<mn){
                mn=diff;
                mnidx=i;
            }
        }
        return mnidx;   
    }
};
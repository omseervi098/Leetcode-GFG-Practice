class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt1=0;
        for(auto i:nums) if(i==1) cnt1++;
        int n=nums.size(),mn=INT_MAX;
        if(cnt1>0) return n-cnt1;
        for(int i=0;i<n;i++){
             int val=nums[i];
            for(int j=i;j<n;j++){
                val=__gcd(nums[j],val);
                if(val==1){
                    int size=j-i;
                    mn=min(mn,size);
                }cout<<endl;
            }
        }
        if(mn==INT_MAX) return -1;
        return n+mn-1;
    }
};
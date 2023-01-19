class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum=0;
        unordered_map<int,int> mp;
        for(auto i:nums){
            sum+=(i%k+k)%k;
            mp[sum%k]++;
        }
        int ans=mp[0];
        for(auto [i,c]:mp){
            ans+=(c*(c-1))/2.0;
        }
        return ans;
    }
};
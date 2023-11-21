class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        int ans=0,mod=1e9+7;
        unordered_map<long long,int> mp;
        for(auto i:nums){
            int temp=i,j=0;
            while(temp>0){
                j=j*10+temp%10;
                temp/=10;
            }
            if(mp.count(i-j)>0) ans=(ans+mp[i-j])%mod;
            mp[i-j]++;
        }
        return ans;
    }
};
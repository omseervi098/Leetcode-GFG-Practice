class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i:nums)
            mp[i]++;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int temp=nums[i];
            while(mp.count(temp-1)>0 and mp[temp-1]>0){
                temp--;mp[temp]--;
            }
            int temp1=nums[i];
            while(mp.count(temp1+1)>0 and mp[temp1+1]>0){
                temp1++;mp[temp1]--;
            }
            mp.erase(nums[i]);
            cout<<ans<<endl;
            ans=max(ans,temp1-temp+1);
        }
        return ans;
    }
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
          unordered_map<int,int> mp;
        for(auto i:nums)
            mp[i]++;
        int ans=0;
        for(auto i:mp){
            if(mp.count(i.first-1)==0){
                int temp1=i.first,cnt=1;
                while(mp.count(temp1+1)>0 and mp[temp1+1]>0){
                    temp1++;cnt++;
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};
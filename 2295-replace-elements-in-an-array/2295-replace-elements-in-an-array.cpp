class Solution {
    
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& op) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++) mp[nums[i]]=i;
        for(auto i:op){
            int idx=mp[i[0]];
            nums[mp[i[0]]]=i[1];
            mp.erase(i[0]);
            mp[i[1]]=idx;
        }
        return nums;
    }
};
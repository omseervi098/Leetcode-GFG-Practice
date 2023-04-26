class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        map<int,int> mp;
        for(int i=0;i<k-1;i++){
            if(nums[i]<0) mp[nums[i]]++;
        }
        vector<int> v;
        for(int i=k-1;i<nums.size();i++){
            if(nums[i]<0) mp[nums[i]]++;
            if(i>=k) mp[nums[i-k]]--;
            int tmp=0;
            for(auto j:mp){
                tmp+=j.second;
                if(tmp>=x){
                    v.push_back((j.first<0)?j.first:0);
                    break;
                }
            }
            if(tmp<x) v.push_back(0);
        }
        return v;
    }
};
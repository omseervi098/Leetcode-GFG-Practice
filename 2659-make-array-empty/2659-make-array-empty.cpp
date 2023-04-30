class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        int n = nums.size(),prev=n;
        long long cnt=0;
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();i++) v.push_back({nums[i],i});
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            if(prev>v[i].second)
                cnt+=n-i;
            else
                cnt+=0;
            prev=v[i].second;
        }
        return cnt;
    }
};
#define ll long long
class Solution {
    public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        set<vector<int>> v;
        sort(nums.begin(),nums.end());
        unordered_map<long long,int> m;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    ll temp=(ll)target-(ll)nums[k]-(ll)nums[i]-(ll)nums[j];
                    while(m[temp]>0){
                        v.insert({nums[i],nums[j],(int)temp,nums[k]});
                        m[temp]--;
                    }
                    m[nums[k]]++;
                }
                m.clear();
            }
        }
        vector<vector<int>> ans;
        for(auto i:v) ans.push_back(i);
        return ans;
    }
};
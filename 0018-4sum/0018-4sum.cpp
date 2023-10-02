#define ll long long
#define umap unordered_map<long long,int>
class Solution {
    public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        set<vector<int>> v;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            if(i>0 and nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n-1;j++){
                if(j>i+1 and nums[j]==nums[j-1]) continue;
               ll ntarget=(ll)target-(ll)nums[i]-(ll)nums[j];
                int l=j+1,h=n-1;
                while(l<h){
                    if(nums[l]+nums[h]<ntarget){
                        l++;
                    }else if(nums[l]+nums[h]>ntarget) h--;
                    else {
                        v.insert({nums[i],nums[j],nums[l],nums[h]});
                        int tempst=l,tempend=h;
                        while(tempst<tempend and nums[l]==nums[tempst]) tempst++;
                        while(tempend>tempst and nums[h]==nums[tempend]) tempend--;
                        l=tempst;
                        h=tempend;
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for(auto i:v) ans.push_back(i);
        return ans;
    }
};
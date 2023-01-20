class Solution {
public:
    void helper(vector<int>&nums,set<vector<int>> &ans,vector<int>& temp,int st,int n){
        if(st>=n){
            if(temp.size()>=2)
                ans.insert(temp);
            return;
        }
        if(!temp.size()||nums[st]>=temp.back()){
            temp.push_back(nums[st]);
            helper(nums,ans,temp,st+1,n);
            temp.pop_back();
        }
        helper(nums,ans,temp,st+1,n);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> fans;
        set<vector<int>> ans;
        vector<int> temp;
        helper(nums,ans,temp,0,nums.size());
        for(auto i:ans) fans.push_back(i);
        return fans;
    }
};
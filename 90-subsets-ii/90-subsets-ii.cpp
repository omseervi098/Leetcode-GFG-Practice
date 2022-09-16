class Solution {
    public:
    void helper(vector<int> &nums,int st,vector<vector<int>> &v,vector<int> &temp){
        v.push_back(temp);
        for(int i=st;i<nums.size();i++){
            if(i>st and nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            helper(nums,i+1,v,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>v;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        helper(nums,0,v,temp);
        return v;
    }
    
    
};
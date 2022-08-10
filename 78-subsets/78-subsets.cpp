class Solution {
public:
    void helper(vector<int> &nums,int st,vector<vector<int>> &v,vector<int> &temp){
        
            v.push_back(temp);

        
        for(int i=st;i<nums.size();i++){
            temp.push_back(nums[i]);
            helper(nums,i+1,v,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>v;
        vector<int> temp;
        helper(nums,0,v,temp);
        return v;
    }
};
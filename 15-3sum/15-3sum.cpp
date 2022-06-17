class Solution {
public:
    vector<vector<int>> twosum(vector<int> &input,int st,int end,int k){
        vector<vector<int>>ans(0,vector<int>(3));
        while(st<end){
            if(input[st]+input[end]>k)
                end--;
            else if(input[st]+input[end]<k)
                st++;
            else{
                ans.push_back({-1*k,input[st],input[end]});
                int ts=st+1;
                int te=end-1;
                while(ts<=te and input[ts]==input[st])
                    ts++;
                while(te>=ts and input[te]==input[end]){
                    te--;
                }
                st=ts;
                end=te;
            }
        }
        return ans;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
       if(nums.size()<2)
           return {};
        vector<vector<int>> cpy;
        int k=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            vector<vector<int>>v=twosum(nums,i+1,nums.size()-1,-nums[i]);
            cpy.insert(cpy.end(),v.begin(),v.end());
            while(i+1<nums.size() and nums[i+1]==nums[i])
                i++;
        }
        return cpy;
    }
};
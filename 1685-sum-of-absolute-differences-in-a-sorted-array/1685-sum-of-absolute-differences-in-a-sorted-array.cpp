class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size(),sm=0;
        vector<int> sufsm(n+1,0),ans;
        for(int i=n-1;i>=0;i--) sufsm[i]=sufsm[i+1]+nums[i];
        for(int i=0;i<n;i++){
            ans.push_back((i*nums[i]-sm)+(sufsm[i]-(n-i)*nums[i]));
            sm+=nums[i];
        }
        return ans;
    }
};
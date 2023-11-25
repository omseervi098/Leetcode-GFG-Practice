class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int> presm(n+1,0),sufsm(n+1,0),ans;
        for(int i=0;i<n;i++) presm[i+1]=presm[i]+nums[i];
        for(int i=n-1;i>=0;i--) sufsm[i]=sufsm[i+1]+nums[i];
        for(int i=0;i<n;i++){
            ans.push_back((i*nums[i]-presm[i])+(sufsm[i]-(n-i)*nums[i]));
        }
        return ans;
    }
};
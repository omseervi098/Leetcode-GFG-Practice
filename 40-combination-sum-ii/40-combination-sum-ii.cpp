class Solution {
public:
    void helper(vector<int> v,vector<int> temp,vector<vector<int>> &ans,int sum,int st,vector<bool> &dp){
   
            if(sum==0){
                ans.push_back(temp);
                return;
            }else if(sum<0 ||st==v.size())
                return;
        
        for(int i=st;i<v.size();i++){
            if(i>st and v[i]==v[i-1]) continue;
            if(sum-v[i]>=0){
                temp.push_back(v[i]);
                helper(v,temp,ans,sum-v[i],i+1,dp);
                temp.pop_back();
            }
        }  
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        int n=candidates.size();
        vector<vector<int>> v;
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        vector<bool> dp(candidates.size());
        helper(candidates,temp,v,target,0,dp);
        return v;
    }
};
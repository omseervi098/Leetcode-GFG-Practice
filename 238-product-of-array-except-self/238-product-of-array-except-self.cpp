class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int totalprod=1;
        int cnt0=0;
        int flag=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                cnt0++;
                if(cnt0==1) flag=i;
            }
            else totalprod*=nums[i];
        }
        vector<int> ans(nums.size(),0);
        if(cnt0>=2)
            return ans;
        else if(cnt0==1){
            ans[flag]=totalprod;
            return ans;
        }
        for(int i=0;i<ans.size();i++){
                ans[i]=(totalprod/nums[i]);    
        }
        return ans;
    }
};
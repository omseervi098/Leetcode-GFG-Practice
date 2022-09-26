class Solution {
public:
    int helper(vector<int>&v,int st,int end,int arr[]){
        if(st==end)
            return end;
        else if(st>end)
            return st;
        if(arr[st]!=-1)return arr[st];
        int ans=0;
        for(int i=1;i<=v[st];i++){
           if(i>end)return false;
            ans=helper(v,st+i,end,arr);
            if(ans==end)break;
        }
        arr[st]=ans;
        return ans;
    }
    bool canJump(vector<int>& nums) {
        int arr[nums.size()+1];
        for(int i=0;i<=nums.size();i++)
            arr[i]=-1;
        int ans=helper(nums,0,nums.size()-1,arr);
        if(ans==nums.size()-1)
            return true;
        else
            return false;
    }
};
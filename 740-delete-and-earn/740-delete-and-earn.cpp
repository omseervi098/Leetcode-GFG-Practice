class Solution {
public:
    int helper(vector<int>&nums,int st,int* arr){
        if(st>=nums.size())
            return 0;
        if(arr[st]!=-1)
            return arr[st];
        int ni=st;
        int sum=0;
        while(ni<nums.size()&&nums[ni]==nums[st]){
            ni++;sum+=nums[st];
        } 
        while(ni<nums.size()&&nums[ni]==nums[st]+1)
            ni++;
        int x=sum+helper(nums,ni,arr);
        int y=helper(nums,st+1,arr);
        arr[st]=max(x,y);
        return arr[st];
        
    }
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int arr[nums.size()+1];
        for(int i=0;i<=nums.size();i++)
            arr[i]=-1;
        return helper(nums,0,arr);
        
    }
};
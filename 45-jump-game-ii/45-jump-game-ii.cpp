class Solution {
public:
    int helper(vector<int>&v,int st,int end,int arr[]){
        if(st>=end){
            return 0;
        }
        if(v[st]==0){
            arr[st]=INT_MAX;
            return INT_MAX;}
        if(arr[st]!=-1)return arr[st];
        int minn=INT_MAX;
        for(int i=1;i<=v[st];i++){
            int ans=helper(v,st+i,end,arr);
            if(ans!=INT_MAX)
                ans+=1;
            minn=min(ans,minn);
        }
        arr[st]=minn;
        return arr[st];
    }
    int jump(vector<int>& nums) {
        int arr[nums.size()+1];
        for(int i=0;i<=nums.size();i++)
            arr[i]=-1;
        return helper(nums,0,nums.size()-1,arr);
        
    }
};
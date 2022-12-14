class Solution {
public:
    int helper(int * arr,int n,int* help){
        if(n<=0){
            return 0;
        }
        if(help[n]!=-1)
            return help[n];
        int x=arr[0]+helper(arr+2,n-2,help);
        int y=helper(arr+1,n-1,help);
        help[n]=max(x,y);
        return help[n];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        int a[n];
        for(int i=0;i<n;i++)
            a[i]=nums[i];
        int help[n+1];
        for(int i=0;i<=n;i++)
            help[i]=-1;
        return helper(a,n,help);
    }
};
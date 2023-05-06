class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        long long ans=0;
        int mod=1e9+7;
        int powers[100001]={};
        powers[0]=1;
        for(int i=1;i<100001;i++){
            powers[i]=(powers[i-1]*2)%mod;
        }
        for(int i=0;i<nums.size();i++)
        {
            int maxi=find(nums,i,target);
            if(maxi!=-1)
            {
                int y=maxi-i;
                ans=(ans+powers[y])%mod;
            }
        }
        return ans%mod;
        
    }
    int find(vector<int>& nums,int ind,int target)
    {
        int ans=-1;
        int l=ind,h=nums.size()-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(nums[ind]+nums[mid]<=target)
            {
                ans=mid;
                l=mid+1;
            }
            else
            h=mid-1;
        }
        return ans;
    }
};
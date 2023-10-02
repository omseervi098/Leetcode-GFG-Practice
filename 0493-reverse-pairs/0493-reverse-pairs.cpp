class Solution {
public:
    void merge(vector<int> &nums,int st,int mid,int end){
        int i=st,j=mid+1;
        vector<int> newarr;
        while(i<=mid and j<=end){
            if(nums[i]<nums[j]) newarr.push_back(nums[i++]);
            else newarr.push_back(nums[j++]);
        }
        while(i<=mid) newarr.push_back(nums[i++]);
        while(j<=end) newarr.push_back(nums[j++]);
        for(i=st;i<=end;i++){
            nums[i]=newarr[i-st];
        }
    }
    int countpair(vector<int> &nums,int st,int mid,int end){
        int i=st,j=mid+1,cnt=0;
        for(;i<=mid;i++){
            while(j<=end and nums[i]>(2*1ll*nums[j])) j++;
            cnt+=j-mid-1;
        }
        return cnt;
    }
    int mergesort(vector<int> &nums,int st,int end){
        if(st>=end) return 0;
        int mid=(st+end)/2.0;
        int left=mergesort(nums,st,mid);
        int right=mergesort(nums,mid+1,end);
        int cnt=countpair(nums,st,mid,end);
        merge(nums,st,mid,end);
        return left+right+cnt;
    }
    int reversePairs(vector<int>& nums) {
    
        return mergesort(nums,0,nums.size()-1);
    }
};
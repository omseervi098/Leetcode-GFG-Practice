class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i=0;
        for( i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1])
                break;
        }
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end()-i);
        reverse(nums.begin()+nums.size()-i,nums.end());
        cout<<endl;
        for(auto it:nums)
            cout<<it<<" ";
        cout<<endl;
        int st=0,end=nums.size()-1;
        while(st<=end){
            int mid=(st+end)/2.0;
            cout<<mid<<endl;
            if(nums[mid]==target)
                return (mid+i)%nums.size();
            else if(nums[mid]>target){
                end=mid-1;
            }else{
                st=mid+1;
            }    
        }
        return -1;
    }
};
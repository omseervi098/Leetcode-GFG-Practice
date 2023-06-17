class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(),idx=-1,temp=0,next=INT_MAX;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                idx=i;
                break;
            }
        }
        if(idx==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int j=idx+1;j<n;j++){
            if(nums[j]>nums[idx]){
                if(nums[j]<=next){
                    temp=j;
                    next=nums[j];
                }
            }
        }
        cout<<idx<<" "<<temp<<endl;
            swap(nums[idx],nums[temp]);
        reverse(nums.begin()+idx+1,nums.end());
    }
};
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1=INT_MIN,ele2=INT_MIN,cnt1=0,cnt2=0;
        for(int i=0;i<nums.size();i++){
            if(cnt1==0 and nums[i]!=ele2){
                ele1=nums[i];
                cnt1++;
            } 
            else if(cnt2==0 and nums[i]!=ele1) {
                ele2=nums[i];
                cnt2++;
            }
            else if(nums[i]==ele1) cnt1++;
            else if(nums[i]==ele2) cnt2++;
            else{
                cnt1--;cnt2--;
            }
        }
        cnt1=0,cnt2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele1) cnt1++;
            if(nums[i]==ele2) cnt2++;
        }
        vector<int> v;
        if(cnt1>nums.size()/3.0) v.push_back(ele1);
        if(cnt2>nums.size()/3.0) v.push_back(ele2);
        return v;
    }
};
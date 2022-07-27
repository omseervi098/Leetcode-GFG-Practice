class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int mx=INT_MIN,cnt=0;
        for(auto it:nums){
            if(cnt==0){
                mx=it;
                ++cnt;
            }else if(mx!=it)
                --cnt;
            else
                ++cnt;
        }
        return mx;
    }
};
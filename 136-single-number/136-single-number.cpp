class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int  sum=0;
        for(auto it:nums)
            sum^=it;
        return sum;
    }
};
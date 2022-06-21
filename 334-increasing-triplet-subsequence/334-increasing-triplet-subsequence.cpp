class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int mn1=INT_MAX,mn2=INT_MAX;
        for(int it:nums){
            if(it<=mn1) mn1=it;
            else if(it<=mn2) mn2=it;
            else return true;
        }return false;
    }
};
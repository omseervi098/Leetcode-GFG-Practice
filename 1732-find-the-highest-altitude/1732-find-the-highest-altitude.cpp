class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sm=0,mx=0;
        for(auto i:gain){
            sm+=i;
            mx=max(sm,mx);
        }
        return mx;
    }
};
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int st=0,end=piles.size()-1,sm=0;
        while(st<end){
            sm+=piles[--end];
            end--;
            st++;
        }
        return sm;
    }
};
class Solution {
public:
    int countOdds(int low, int high) {
        int cnt=0;
        if(high%2==0 and low%2==0){
            cnt+=(high-low)/2;
            return cnt;
        }
        cnt+=(high-low-1)/2;
        if(low%2==1)cnt++;
        if(high%2==1 and high!=low)cnt++;
        return cnt;
    }
};
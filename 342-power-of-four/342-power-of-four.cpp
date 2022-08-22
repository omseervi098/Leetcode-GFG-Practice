class Solution {
public:
    bool isPowerOfFour(int n) {
        double ans=((log2(n))/2);
        return (ans-floor(ans))==0?1:0;
    }
};
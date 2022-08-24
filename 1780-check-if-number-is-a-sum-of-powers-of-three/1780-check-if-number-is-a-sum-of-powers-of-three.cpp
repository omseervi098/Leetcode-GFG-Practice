class Solution {
public:
    bool convertToTernary(int N)
   {
        if (N == 0)
           return true;
        int x = N % 3;
        N /= 3;
        if (x < 0)
           N += 1;
        if(x==2) return false;
        bool ans=convertToTernary(N);
        return ans;
   }
    bool checkPowersOfThree(int n) {
        return convertToTernary(n);
    }
};
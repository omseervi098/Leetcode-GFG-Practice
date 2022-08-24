class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0||n>1162261467){
            return false;
        }
        int ans=1162261467;
        return ans%n==0;
    }
};
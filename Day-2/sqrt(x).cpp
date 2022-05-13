//problem no 69
class Solution {
public:
    int mySqrt(int x) {
        long long int ans=0;
        int cnt=0;
        while(ans*ans<=x){
            ans+=1;
            cnt++;
        }
        return cnt-1;
    }
};
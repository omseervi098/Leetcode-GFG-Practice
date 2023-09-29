class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        //Binary Exponentiation
        if(n<0){
            n=abs(n);
            while(n>0){
                if(n%2==0){
                    x*=x;
                    n=n/2;
                }else{
                    ans/=x;
                    n--;
                }
            }
        }else{
            while(n>0){
                if(n%2==0){
                    x*=x;
                    n=n/2;
                }else{
                    ans*=x;
                    n--;
                }
            }
        }
        return ans;
    }
};
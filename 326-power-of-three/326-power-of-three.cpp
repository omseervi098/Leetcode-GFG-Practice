class Solution {
public:
    bool isPowerOfThree(int n) {
        double log3=log10(3);
        double logn=log10(n);
        double ans=logn/log3;
        //cout<<ans<<endl;
        
         
        //cout<<temp<<endl;
        double check=abs(ans-floor(ans));
        //cout<<check;
        if(check==0){
            return true;
        }else
        return false;
    }
};
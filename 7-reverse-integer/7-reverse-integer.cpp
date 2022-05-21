class Solution {
public:
    int reverse(int x) {
        int neg=1;
        if(x==INT_MIN)return 0;
        if(x<0){
            neg=-1;
            x=neg*x;
        }
        int ans=0;
        while(x>0){
            if(neg*ans>INT_MAX/10||neg*ans<INT_MIN/10)
                return 0;
            ans=ans*10+x%10;
            
            x/=10;
        }
        return (int)(neg*ans);
    }
};
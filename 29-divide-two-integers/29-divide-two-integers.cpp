class Solution {
public:
    int divide(int div, int d) {
        int neg=1;  
        if((div>0 and d>0) || (div<0 and d<0)){
            if(d==-1 and div==INT_MIN) return INT_MAX;
            if(d==1 and div==INT_MIN) return INT_MAX;
            neg=1;
        }else{
            
            neg=-1;
        }
        long long int a=abs(div);
        long long int b=abs(d);
        unsigned int curr=1;
        int ans=0;
        if(b==1) return neg*a;
        if(b==0){
            return -1;
        }
        if(a<b){
            return 0;
        }
        if(a==b){
            return neg*1;
        }
        
        while(a>=b){
            b<<=1;
            curr<<=1;
        }
        b>>=1;
        curr>>=1;
        while(curr!=0){
            if(a>=b){
                a-=b;
                ans=ans|curr;
            }
            b>>=1;
            curr>>=1;
        }
        return ans*neg;
    }
};
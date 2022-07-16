class Solution {
public:
    bool isHappy(int n) {
        while(n>6){
            int sum=0;
            int cpy=0;
            while(n>0){
                sum+=(n%10)*(n%10);
                n/=10;
            }n=sum;
            
        }if(n==1)return true;
        return false;
    }
};
class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum=0,prod=1,cpy=n;
        while(cpy>0){
            sum+=cpy%10;
            prod*=cpy%10;
            cpy/=10;
        }
        return prod-sum;
    }
};
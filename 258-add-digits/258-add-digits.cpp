class Solution {
public:
    int addDigits(int num) {
        if(num>=0 and num<=9) return num;
        int sm=0;
        while(num){
            sm+=num%10;
            num/=10;
        }
        return addDigits(sm);
    }
};
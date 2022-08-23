class Solution {
public:
    int addDigits(int num) {
        if(num<=9){
            return num;
        }
        int temp=num;
        num=0;
        while(temp>0){
            num+=temp%10;
            temp/=10;
        }
        return addDigits(num);
    }
};
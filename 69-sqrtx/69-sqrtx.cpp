class Solution {
public:
    int mySqrt(long long int x) {
        long long int st=0,end=x;
        while(st<=end){
            long long int mid=(st+end)/2;
            if(mid*mid==x){
                return mid;
            }else if(mid*mid>x){
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        return end;
    }
};
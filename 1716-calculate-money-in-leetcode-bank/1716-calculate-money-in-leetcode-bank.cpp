class Solution {
public:
    int totalMoney(int n) {
        // 10 --> (10/7 ==1 )*(n*(n+1)/2) and 
        int ans=0,tmp=0,cpy=0;
        for(int i=0;i<n;i++){
            if(i%7==0) {
                cpy++;
                tmp=cpy;
            }
            ans+=tmp++;
        }
        return ans;
    }
};
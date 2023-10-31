class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1) return 0;
        if(n==2) return k==1?0:1;
        if(n==3) {
            string temp="0110";
            return temp[k-1]-'0';
        }
        if(k>(1<<(n-2))) 
            return kthGrammar(n-1,k-(1<<(n-2)))==0?1:0;
        else{
            return kthGrammar(n-1,k);
        }
    }
};
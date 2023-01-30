class Solution {
public:
    int helper(int n,vector<int> &v){
        if(n==0) return 0;
        if(n==1||n==2){
            return 1;
        }
        if(v[n]!=-1) return v[n];
        return v[n]=helper(n-1,v)+helper(n-2,v)+helper(n-3,v);
    }
    int tribonacci(int n) {
        vector<int> v(n+1,-1);
        return helper(n,v);
    }
};
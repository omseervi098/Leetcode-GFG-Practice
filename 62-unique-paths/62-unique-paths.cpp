class Solution {
    public:
    int ncr(int n,int r){
       double res=1;
	   for(int i=1;i<=r;i++){
           res=res*(n-r+i)/i;
       }
       return (int)res;
    } 
    int uniquePaths(int m, int n) {
       return ncr(n+m-2,m-1);
    }
};
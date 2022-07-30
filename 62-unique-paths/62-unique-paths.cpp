class Solution {
public:
    int helper(int m,int n,int x,int y,vector<vector<int>> &ans){
        if(x<0||y<0||x==m||y==n) return 0;
        if(x==m-1 and y==n-1)return 1;
        if(ans[x][y]!=-1)return ans[x][y];
        int a=helper(m,n,x+1,y,ans);
        int b=helper(m,n,x,y+1,ans);
        ans[x][y]=a+b;
        return a+b;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>ans(m+1,vector<int>(n+1,-1));
        return helper(m,n,0,0,ans);
    }
};
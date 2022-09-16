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
        vector<int> prevr(n,0);
	for(int i=0;i<m;i++){
		vector<int> row(n,0);
		for(int j=0;j<n;j++){
			if(i==0 and j==0) row[j]=1;
			else {
			    int up=0,left=0;
			    if(i>0) up=prevr[j];
			    if(j>0) left=row[j-1];
			    row[j]=up+left;
		    }
		}
		prevr=row;
	}
	return prevr[n-1];
    }
};
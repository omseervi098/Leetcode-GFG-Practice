class Solution {
public:
   int find(vector<vector<int>>& obstacle,int m,int n){
    vector<vector<int>>dp(m,vector<int>(n));
	bool flag=false;
	for(int i=0;i<n;i++)
	{
		if(flag || obstacle[0][i]==1)
			{dp[0][i]=0;flag=true;}
		else
			dp[0][i]=1;
	}
	flag=false;
	for(int i=0;i<m;i++)
	{
		if(flag || obstacle[i][0]==1)
			{dp[i][0]=0;flag=true;}
		else
			dp[i][0]=1;
	}
	for(int i=1;i<m;i++){
		for(int j=1;j<n;j++){
			if(obstacle[i][j]==1)
				dp[i][j]=0;
			else
				dp[i][j]=dp[i-1][j]+dp[i][j-1];
		}
	}
	return dp[m-1][n-1];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        int r=find(obstacleGrid,m,n);
        return r;
        
    }
};
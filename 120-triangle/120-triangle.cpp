class Solution {
public:
    int helper(vector<vector<int>> &tri,int row,int size,int i, vector<vector<int>>& dp){
        if(row==size){
            return 0;
        }
        if(dp[row][i]!=-999999)
            return dp[row][i];
        int isum= tri[row][i]+helper(tri,row+1,size,i,dp);
        int i1sum=tri[row][i]+helper(tri,row+1,size,i+1,dp);
        dp[row][i]=min(isum,i1sum);
        return dp[row][i];
    }
    int minimumTotal(vector<vector<int>>& v) {
        int n=v.size();
	vector<int> curr(n);
	for(int i=0;i<n;i++){
		curr[i]=v[n-1][i];
	}
	for(int i=n-2;i>=0;i--){
		vector<int> temp(n);
		for(int j=i;j>=0;j--){
			temp[j]=v[i][j]+min(curr[j],curr[j+1]);
		}
		curr=temp;
	}
	return curr[0];

    }
};
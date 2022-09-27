class Solution {
public:
    int DPOptimised(vector<vector<int>> &v){
	int n=v.size();
	vector<int> prev(n,0),curr(n,0);
	for(int j=0;j<n;j++) prev[j]=v[0][j];
	for(int i=1;i<n;i++){
		for(int j=0;j<n;j++){
			int a=INT_MAX,b=prev[j],c=INT_MAX;
			if(j-1>=0) a=prev[j-1];
			if(j+1<n) c=prev[j+1];
			int mx=min(a,min(b,c));
			if(mx!=INT_MAX)
			curr[j]=v[i][j]+mx;
		}
		prev=curr;
	}
	int mx=INT_MAX;
	for(int j=0;j<n;j++) mx=min(mx,prev[j]);
	return mx;
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
        return DPOptimised(matrix);
    }
};
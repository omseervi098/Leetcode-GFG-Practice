class Solution {
public:
    int DP(vector<int> &v){
	int n=v.size();
	int prev1=v[0],prev2=0;
	for(int i=1;i<n;i++){
		int inc=v[i];
		if(i>1) inc+=prev2;
		int curr=max(inc,prev1);
		prev2=prev1;
		prev1=curr;
	}
	return prev1;
}
    int rob(vector<int>& v) {
        int n=v.size();
        if(n==0) return 0;
        if(n==1) return v[0];
        vector<int> temp,temp2;
	   for(int i=0;i<n;i++){
		  if(i!=0) temp.push_back(v[i]);
		   if(i!=n-1) temp2.push_back(v[i]);
     	}
        return max(DP(temp),DP(temp2));
    }
};
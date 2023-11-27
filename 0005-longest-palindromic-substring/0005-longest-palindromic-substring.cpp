class Solution {
    vector<vector<int>> dp;
  public:
    int generatesubset(string &s,int st,int end,int &l,int &r){
        if(st>end) return 0;
        if(st==end) return 1;
        if(dp[st][end]!=-1) return dp[st][end];
        if(s[st]==s[end]){
            int subans=generatesubset(s,st+1,end-1,l,r);
            if(end-st+1==subans+2){
                if((end-st+1)>(r-l+1)){
                    l=st;
                    r=end;
                }
                return dp[st][end]=end-st+1;
            }
        }
        int mx=0;
        int a=generatesubset(s,st+1,end,l,r);
        int b=generatesubset(s,st,end-1,l,r);
        return dp[st][end]=max(a,b);
    }
    string longestPalindrome(string s) {
        // starting point and size
        dp.resize(s.size(),vector<int>(s.size(),-1));
        int l=0,r=0;
        generatesubset(s,0,s.size()-1,l,r);
        return s.substr(l,r-l+1);
    }
};
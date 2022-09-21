class Solution {
    vector<int> dp;
public:
    int helper(string s,int st,int n){
        if(st>=n) return 1;
        char temp=s[st];
        int a=0,b=0;
        if(dp[st]!=-1) return dp[st];
        if(temp>='1' and temp<='9'){
            a=helper(s,st+1,n);
        }
        if(st+1<n){
            int tmp=(s[st]-'0')*10+(s[st+1]-'0');
        
            if(tmp>=10 and tmp<=26){
                b=helper(s,st+2,n);
            }
        }
        return dp[st]=a+b;
    }
    int numDecodings(string s) {
        dp.resize(s.size(),-1);
        return helper(s,0,s.size());
    }
};
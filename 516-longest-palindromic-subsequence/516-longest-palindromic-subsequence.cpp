class Solution {
    vector<vector<int>> dp;
    unordered_map<string,int> mp;
    bool palindrome(string s){
        int st=0,end=s.size()-1;
        while(st<=end){
            if(s[st]!=s[end]){
                return false;
            }
            st++;end--;
        }
        return true;
    }
    int helper(string &s,int st,int end,string out){
        if(st>end){
            return 0;
        }
        if(st==end){
            return 1;
        }
        if(dp[st][end]!=-1) return dp[st][end];
        if(s[st]==s[end]){
            return helper(s,st+1,end-1,out)+2;
        }else{
            return dp[st][end]=max(helper(s,st+1,end,out),helper(s,st,end-1,out));
        }
    }
    public:
    int longestPalindromeSubseq(string s) {
        dp.resize(s.size()+1,vector<int> (s.size()+1,-1));
        return helper(s,0,s.size()-1,"");
    }
};
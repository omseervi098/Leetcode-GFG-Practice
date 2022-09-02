class Solution {
public:
    void helper(vector<string> &v,string s,int n,int m){
        if(m==0 && n==0){
            v.push_back(s);
            return;
        }
        if(m>0)
            helper(v,s+")",n,m-1);
        if(n>0)
            helper(v,s+"(",n-1,m+1);
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        helper(v,"",n,0);
        return v;
    }
};
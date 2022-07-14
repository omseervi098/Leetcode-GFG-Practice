class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1)return s;
       string temp="";
        vector<string> dp(numRows,"");
        for(int i=0,row=0,step=1;i<s.size();i++){
            dp[row]+=s[i];
            if(row==0) step=1;
            else if(row==numRows-1) step=-1;
            row+=step;
        }
        for(auto it:dp)
            temp+=it;
        return temp;
    }
};
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        for(int i=0;i<num.size();i++){
            while(s.size() and num[i]<s.top() and k>0) {s.pop();k--;}
            s.push(num[i]);
        }
        string ans="";
        while(s.size() and k-->0) s.pop();
        while(s.size()) {ans+=s.top();s.pop();}
       
        int end=ans.size()-1;
        while(end>=0 and ans[end]=='0') end--;
        ans=ans.substr(0,end+1);
        if(ans.size()==0) return "0";
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
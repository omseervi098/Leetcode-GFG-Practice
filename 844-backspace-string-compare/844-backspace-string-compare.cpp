class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1="",s2="";
        int m=s.size(),n=t.size();
        int i=0;
        while(i<m){
            if(s[i]!='#'){
                s1+=s[i];   
            }
            if(s[i]=='#' and s1.size()>=1){
                s1.pop_back();
            }i++;
        }i=0;
    
        while(i<n){
            if(t[i]!='#'){
                s2+=t[i];
            }
            if(t[i]=='#' and s2.size()>=1){
                s2.pop_back();
            }i++;
        }
        cout<<s1<<" "<<s2<<endl;
        return s1==s2;
    }
};
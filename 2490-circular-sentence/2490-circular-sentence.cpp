class Solution {
public:
    bool isCircularSentence(string s) {
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]==' ' and i+1<n and s[i+1]!=s[i-1]) return false;
            if(i==n-1 and s[i]!=s[0]) return false;
        }
        return true;
    }
};
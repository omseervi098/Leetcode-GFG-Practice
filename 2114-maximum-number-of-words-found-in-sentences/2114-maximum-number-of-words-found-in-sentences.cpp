class Solution {
public:
    int mostWordsFound(vector<string>& sen) {
        int mx=INT_MIN;
        for(int i=0;i<sen.size();i++){
            string s=sen[i];
            int l=0,st=0;
            for(int j=0;j<=s.size();j++){
                if(s[j]==' '||s[j]=='\0'){
                    l++;
                }
            }
            mx=max(l,mx);
        }return mx;
    }
};
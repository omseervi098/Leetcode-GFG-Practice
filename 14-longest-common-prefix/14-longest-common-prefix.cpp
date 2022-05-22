class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s,next;
        for(int i=0;i<strs.size();i++){
            int j;
            if(i==0){
            string temp="";
                s=strs[i];
            for(j=0;j<strs[i].size();j++){
                if(strs[i][j]!=s[j])
                    break;
                else
                    temp+=strs[i][j];
            }s=temp;
            }
            else
            {
                string temp="";
                for(int j=0;j<strs[i].size();j++){
                    if(strs[i][j]!=s[j])
                        break;
                    else
                        temp+=strs[i][j];
                }
                s=temp;
            }
            
        }
        return s;
    }
};
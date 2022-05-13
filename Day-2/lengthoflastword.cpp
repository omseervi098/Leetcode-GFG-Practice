//problem no 58
class Solution {
public:
    int lengthOfLastWord(string s) {
        int j=0;
        int i=0;
        for(i=s.size()-1;i>=0;i--){
            if(s[i]!=' ')
                break;
        }j=i;
        int cnt=0;
        i=0;
        for(i=j;i>=0;i--){
            if(s[i]==' '){
                break;
            }
        }
        cnt=j-i;
        return cnt;
    }
};
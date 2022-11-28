class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0;
        for(int j=0;j<s.size();j++)
        {
            if(s[j]==t[i]) i++;
        }
        return t.size()-i;
    }
};
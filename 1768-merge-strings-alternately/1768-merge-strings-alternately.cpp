class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string str="";
        int j=0;
        for(int i=0;i<word1.size();i++){
             str+=word1[i];
            if(j<word2.size())
            str+=word2[j++];
         }
        while(j<word2.size())
            str+=word2[j++];
        return str;
    }
};
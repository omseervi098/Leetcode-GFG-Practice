class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> m;
        unordered_map<char,bool> m1;
        for(int i=0;i<s.size();i++){
            if(m.count(s[i])>0){
                if(t[i]!=m[s[i]]) return false;
                
            }else{
                if(m1.count(t[i])>0) return false;
                m[s[i]]=t[i];
                m1[t[i]]=true;
            }
        }
        return true;
    }
};
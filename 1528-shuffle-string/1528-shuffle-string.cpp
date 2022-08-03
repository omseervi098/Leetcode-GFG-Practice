class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n=s.size();
        unordered_map<int,char> m;
        for(int i=0;i<n;i++){
            m[indices[i]]=s[i];
        }
        s="";
        for(int i=0;i<n;i++){
            s+=m[i];
        }
        return s;
    }
};
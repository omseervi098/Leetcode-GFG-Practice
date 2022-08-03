class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n=s.size();
        map<int,char> m;
        for(int i=0;i<n;i++){
            m[indices[i]]=s[i];
        }
        s="";
        for(auto it:m){
            s+=it.second;
        }
        return s;
    }
};
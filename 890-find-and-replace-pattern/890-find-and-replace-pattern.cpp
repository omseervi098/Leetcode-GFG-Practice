class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string p) {
        vector<string> ans;
        
        for(auto it:words){
            string s=it;
            unordered_map<char,char> m;
            unordered_map<char,bool> visited;
            int i=0,n=s.size();
            for(i=0;i<n;i++){
                if(m.count(p[i])>0){
                    if(m[p[i]]!=s[i]){
                        break;
                    }
                }else{
                    if(visited.count(s[i])>0) break;
                    visited[s[i]]=true;
                    m[p[i]]=s[i];
                }
            }
            if(i==n){
                ans.push_back(it);
            }
        }return ans;

    }
};
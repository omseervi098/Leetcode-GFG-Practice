class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size()>s.size())
            return {};
        vector<int> window(26);
        vector<int> freq_p(26);
        for(int i=0;i<p.size();i++){
            freq_p[p[i]-'a']++;
            window[s[i]-'a']++;
        }vector<int> ans;
        if(freq_p==window)ans.push_back(0);
        for(int i=p.size();i<s.size();i++){
            window[s[i-p.size()]-'a']--;
            window[s[i]-'a']++;
            if(window==freq_p)
                ans.push_back(i-p.size()+1);
            
        }return ans;
    }
};
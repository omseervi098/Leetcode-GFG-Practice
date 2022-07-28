class Solution {
public:
    bool checkInclusion(string p, string s) {
        if(p.size()>s.size())
            return {};
        vector<int> window(26);
        vector<int> freq_p(26);
        for(int i=0;i<p.size();i++){
            freq_p[p[i]-'a']++;
            window[s[i]-'a']++;
        }
        if(freq_p==window)return true;
        for(int i=p.size();i<s.size();i++){
            window[s[i-p.size()]-'a']--;
            window[s[i]-'a']++;
            if(window==freq_p)
                return true;
            
        }return false;
        
    }
};
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> v;
        for(auto &i:strs){
            vector<int> freq(26,0);
            for(auto j:i) freq[j-'a']++;
            string temp="";
            for(int k=0;k<26;k++) temp+=freq[k]+'0';
            mp[temp].push_back(i);
        }
        for(auto i:mp)  v.push_back(i.second);
        return v;
    }
};
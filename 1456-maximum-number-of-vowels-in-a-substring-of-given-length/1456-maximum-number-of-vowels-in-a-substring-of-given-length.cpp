class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_map<char,int> mp;
        for(int i=0;i<k-1;i++){
            mp[s[i]]++;
        }
        int mx=0,n=s.size();
        for(int i=k-1;i<n;i++){
             // if(i<k) mp[s[i]]++;
            mp[s[i]]++;
            if(i>=k) mp[s[i-k]]--;
            
            mx=max(mx,(mp['a']+mp['e']+mp['i']+mp['o']+mp['u']));
        }return mx;
    }
};
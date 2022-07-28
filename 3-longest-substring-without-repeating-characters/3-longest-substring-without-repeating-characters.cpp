class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> freq;
        int n=s.size();

        int mx=0,i=0,j;
        for( j=i;j<n;j++){
            if(freq.count(s[j])>0)
            {
                i=max(freq[s[j]],i);
            }
            mx=max(mx,j-i+1);
            freq[s[j]]=j+1;

        }
        return mx;
    }
};
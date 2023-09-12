class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> m;
        unordered_set<int> st;
        for(auto i:s) m[i]++;
        int cnt=0;
        for(auto [a,b]:m){
            while(b>0 and st.count(b)>0){ b--;cnt++;}
            st.insert(b);
        }
        return cnt;
    }
};
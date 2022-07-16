class Solution {
public:
    bool isMatch(string s, string p) {
        regex b(p);
        return regex_match(s,b);
    }
};
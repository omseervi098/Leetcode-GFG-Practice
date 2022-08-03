class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> v;
        v.push_back(first);
        for(auto it:encoded){
            v.push_back(it^first);
            first=it^first;
        }
        return v;
    }
};
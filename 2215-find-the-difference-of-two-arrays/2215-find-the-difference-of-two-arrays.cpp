class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1,s2;
        for(auto i:nums1)    s1.insert(i);
        for(auto i:nums2) {   if(s1.count(i)) s1.erase(i); s2.insert(i); }
        for(auto i:nums1)     if(s2.count(i)) s2.erase(i);
        vector<int> v1,v2;
        for(auto i:s1)  v1.push_back(i);
        for(auto i:s2)  v2.push_back(i);
        return {v1,v2};
    }
};
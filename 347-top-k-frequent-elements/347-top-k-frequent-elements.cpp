class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(auto i:nums) mp[i]++;
        priority_queue<pair<int,int>> pq;
        for(auto i:mp){
            pq.push({i.second,i.first});
        }
        vector<int> v;
        while(pq.size() and k-->0){
            v.push_back(pq.top().second);
            pq.pop();
        }
        return v;
    }
};
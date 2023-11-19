class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int,int> mp;
        unordered_map<int,int> mp1;
        priority_queue<int> pq;
        for(int i=0;i<nums.size();i++)mp[nums[i]]++;
        int k=0,cnt=0;
        for(auto i:mp) {mp1[i.first]=k++;pq.push(i.first);}
        while(pq.size()){
            int top=pq.top();pq.pop();
            cnt+=mp1[top]*mp[top];
        }
        return cnt;
    }
};
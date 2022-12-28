class Solution {
public:
    int minStoneSum(vector<int>& p, int k) {
        priority_queue<int> pq;
        for(auto i:p) pq.push(i);
        int cnt=0;
        while(pq.size() and k>0){
            pq.push(pq.top()-floor(pq.top()/2.0));
            k--;
            pq.pop();
        }
        while(pq.size()){
            cnt+=pq.top();
            pq.pop();
        }
        return cnt;
    }
};
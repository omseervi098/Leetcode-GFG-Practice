
class Solution {
public:

    vector<int> getOrder(vector<vector<int>>& t) {
        int n=t.size();
       
        for(int i=0;i<n;i++)
            t[i].push_back(i);
        sort(t.begin(),t.end());
        vector<int> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        long long i=0,st_time=0;
        while(i<n || pq.size()){
            if(pq.empty()){
                st_time=max(st_time,(long long)t[i][0]);
            }
            while(i<n and st_time>=t[i][0]){
                pq.push({t[i][1],t[i][2]});
                i++;
            }
            auto [x,y]=pq.top();
            pq.pop();
            st_time+=x;
            ans.push_back(y);
        }
        return ans;
    }
    
};
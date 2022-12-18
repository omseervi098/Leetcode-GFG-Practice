class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n=t.size();
        vector<int> ans(n,0);
        stack<int>s;
        s.push(n-1);
        for(int i=n-1;i>=0;i--){
            while(s.size() and t[i] >= t[s.top()]) s.pop();
            ans[i]=s.empty()?0:s.top()-i;
            s.push(i);
        }
        return ans;
    }
};
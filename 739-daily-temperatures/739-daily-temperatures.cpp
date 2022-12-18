class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int> ans(t.size());
        stack<int>s;
        for(int i=t.size()-1;i>=0;i--){
            if(i==t.size()-1)
               ans[i]=0;
            else{
                while(s.size() and t[i] >= t[s.top()]) s.pop();
                if(!s.empty())
                    ans[i]=s.top()-i;
                else
                    ans[i]=0;
            }
            s.push(i);
        }
        return ans;
    }
};
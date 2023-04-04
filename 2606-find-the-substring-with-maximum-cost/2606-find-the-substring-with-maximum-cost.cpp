class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> cost(26,0);
        for(int i=1;i<=26;i++) {
            cost[i-1]=i;
        }
        for(int i=0;i<chars.size();i++){
            cost[chars[i]-'a']=vals[i];
        }
        for(auto i:cost){
            cout<<i<<" ";
        }cout<<endl;
        int mx=0,sm=0;
        for(int i=0;i<s.size();i++){
            sm+=cost[s[i]-'a'];
            if(sm<0){
                sm=0;
            }
            mx=max(mx,sm);
        }
        return mx;
    }
};
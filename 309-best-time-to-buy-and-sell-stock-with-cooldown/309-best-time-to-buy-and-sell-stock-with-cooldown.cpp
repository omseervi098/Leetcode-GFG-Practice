class Solution {
public:
    int find(vector<int> &prices,int st,bool buy,vector<vector<int>> &v){
        if(st>=prices.size()){
            return 0;
        }
        if(v[st][buy]!=-1)return v[st][buy];
        if(buy){
            int notbuy=find(prices,st+1,buy,v);
            int bbuy=-prices[st]+find(prices,st+1,!buy,v);
            return v[st][buy]=max(notbuy,bbuy);
        }
        else {
            int notsell=find(prices,st+1,buy,v);
            int sell=prices[st]+find(prices,st+2,!buy,v);
            return v[st][buy]=max(notsell,sell);
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> v(prices.size(),vector<int>(2,-1));
        return find(prices,0,1,v);
    }
};
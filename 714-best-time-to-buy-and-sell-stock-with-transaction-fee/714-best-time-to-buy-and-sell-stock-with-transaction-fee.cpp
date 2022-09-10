class Solution {
    int fe;
public:
     int find(vector<int> &prices,int st,bool buy,int k,vector<vector<int>> &v){
        if(st>=prices.size()){
            return 0;
        }
        if(v[st][buy]!=-1)return v[st][buy];
        if(buy){
            int notbuy=find(prices,st+1,buy,k,v);
            int bbuy=-prices[st]+find(prices,st+1,!buy,k,v);
            return v[st][buy]=max(notbuy,bbuy);
        }
        else {
            int notsell=find(prices,st+1,buy,k,v);
            int sell=prices[st]+find(prices,st+1,!buy,k+1,v)-fe;
            return v[st][buy]=max(notsell,sell);
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        fe=fee;
        vector<vector<int>> v(prices.size(),vector<int>(2,-1));
        return find(prices,0,1,0,v);
    }
};
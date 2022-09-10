class Solution {
    int m;
    public:
    int find(vector<int> &prices,int st,int k,bool buy,vector<vector<vector<int>>> &v){
        if(st>=prices.size() || k>=m){
            return 0;
        }
        if(v[st][buy][k]!=-1)return v[st][buy][k];
        if(buy){
            int notbuy=find(prices,st+1,k,buy,v);
            int bbuy=-prices[st]+find(prices,st+1,k,!buy,v);
            return v[st][buy][k]=max(notbuy,bbuy);
        }
        else {
            int notsell=find(prices,st+1,k,buy,v);
            int sell=prices[st]+find(prices,st+1,k+1,!buy,v);
            return v[st][buy][k]=max(notsell,sell);
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        m=k;

        vector<vector<vector<int>>> v(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));
        return find(prices,0,0,1,v);
        
    }
};
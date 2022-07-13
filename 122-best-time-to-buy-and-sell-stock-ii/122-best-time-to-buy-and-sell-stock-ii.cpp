class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0,sum=0;
        for(int i=1;i<prices.size();i++){
            int k=prices[i]-prices[i-1];
            if(k<0){
                continue;
            }
            sum+=k;
            ans=max(sum,ans);
        }
        return ans;
    }
};
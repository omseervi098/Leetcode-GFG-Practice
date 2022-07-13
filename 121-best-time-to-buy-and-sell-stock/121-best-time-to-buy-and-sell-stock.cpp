class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int ans=0;
        for(int i=1,j=0;i<prices.size();i++){
            if(prices[i]-prices[j]<0){
                j=i;
            }
            else if(prices[i]-prices[j]>ans){
                ans=prices[i]-prices[j];
            }
            
        }
        return ans;
    }
};
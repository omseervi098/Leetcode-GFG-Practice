class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int k=0;
        int cnt=0;
        long long int temp=coins;
        while(k<costs.size() and temp>=costs[k]){
            temp-=costs[k++];
            cnt++;
        }
        return cnt;
    }
};
class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long int sum=0;
        for(auto it:nums){
            sum+=it;
        }
        //cout<<sum<<endl;
        double lim=(double)limit;
        long long int x=sum-goal;
        double ans=(abs(x))/lim;
        if(ans-floor(ans)==0){
            return floor(ans);
        }
        return floor(ans)+1;
    }
};
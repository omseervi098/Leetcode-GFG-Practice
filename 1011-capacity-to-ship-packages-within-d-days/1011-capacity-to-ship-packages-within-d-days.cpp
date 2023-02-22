class Solution {
public:
    bool possible(vector<int>& weights,int capacity,int days){
        int sm=0,cnt=1;
        for(auto i:weights){
            sm+=i;
            if(sm>capacity){
                sm=i;
                cnt++;
            }
        }
        return cnt<=days;
    }
    int shipWithinDays(vector<int>& weights, int days){
        int left=*max_element(weights.begin(),weights.end());
        int right=accumulate(weights.begin(),weights.end(),0);
        while(left<right){
            int mid=(left+right)/2.0;
            bool check=possible(weights,mid,days);
            if(check){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        return left;
    }
};
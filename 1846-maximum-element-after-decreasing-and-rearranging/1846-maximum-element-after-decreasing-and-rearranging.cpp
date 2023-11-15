class Solution {
    bool check(vector<int> &arr){
        if(arr[0]!=1) return false;
        for(int i=1;i<arr.size();i++){
            if(abs(arr[i]-arr[i-1])>1){
                return false;
            }
        }
        return true;
    }
    public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        bool flag=check(arr);
        if(flag) return arr[n-1];
        else{
            int t=1;
            if(arr[0]!=1) arr[0]=1;
            for(int i=1;i<n;i++){
                while(i<n-1 and arr[i]==t) i++;
                if(arr[i]!=t+1) arr[i]=t+1;
                ++t;
            }
            return t;
        }
    }
};
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
        // sort the array
        sort(arr.begin(),arr.end());
        // check if satisfy 
        bool flag=check(arr);
        if(flag) return arr[arr.size()-1];
        else{
            int t=1;
            if(arr[0]!=1) arr[0]=1;
            for(int i=1;i<arr.size();i++){
                int j=i;
                while(i<arr.size()-1 and arr[i]==t) i++;
                if(arr[i]!=t+1) arr[i]=t+1;
                t++;
            }
            for(auto i:arr) cout<<i<<" ";
            cout<<endl;
            return t;
        }
    }
};
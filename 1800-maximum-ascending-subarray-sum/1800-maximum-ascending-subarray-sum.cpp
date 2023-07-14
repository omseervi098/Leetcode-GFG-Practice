class Solution {
public:
    int maxAscendingSum(vector<int>& arr) {
         int n=arr.size(),mx=0,sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(i+1<n and arr[i]>=arr[i+1]){
                cout<<sum<<endl;
                mx=max(sum,mx);
                sum=0;
            }
        }
        return max(mx,sum);
    }
};
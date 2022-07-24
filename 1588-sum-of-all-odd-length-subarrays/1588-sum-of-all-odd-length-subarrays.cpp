class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n=arr.size();
        int total=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int sum=0;
                if((j-i+1)%2==1){
                for(int k=i;k<=j;k++){
                    sum+=arr[k];
                }}
                total+=sum;
            }
        }return total;
    }
};
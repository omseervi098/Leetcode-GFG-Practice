class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n=arr.size();
        int total=0;
        for(int i=0;i<n;i++){
            total+=arr[i]*(((i+1)*(n-i)+1)/2);
        }return total;
    }
};  
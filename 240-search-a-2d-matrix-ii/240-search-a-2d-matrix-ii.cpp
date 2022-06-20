class Solution {
public:
    bool binarysearch(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        int st=0,end=n-1;
        while(st<=end){
            int mid=(st+end)/2;
            if(arr[mid]==k){
                return true;
            }else if(arr[mid]>k){
                end=mid-1;
            }else
               st=mid+1;
        }return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++){

                bool ans=binarysearch(matrix[i],target);
                if(ans==true)return true;
            }
        return false;
    }
};
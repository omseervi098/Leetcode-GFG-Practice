class Solution {
public:
 
    bool searchMatrix(vector<vector<int>>& arr, int k) {
        for(int i=0;i<arr.size();i++){
                int st=0,end=arr[i].size()-1;
        while(st<=end){
            int mid=(st+end)/2;
            if(arr[i][mid]==k){
                return true;
            }else if(arr[i][mid]>k){
                end=mid-1;
            }else
               st=mid+1;
        }
        }return false;
    }
};
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         for(int i=0;i<matrix.size();i++){
            if(i<matrix.size() and matrix[i][0]>target){
                break;
            }else{
            int st=0,end=matrix[0].size()-1;
            while(st<=end){
                int mid=(st+end)/2.0;
                if(matrix[i][mid]==target)
                    return true;
                else if(matrix[i][mid]>target){
                    end=mid-1;
                }else{
                    st=mid+1;
                }
            }}
        }
        return false;
    }
};
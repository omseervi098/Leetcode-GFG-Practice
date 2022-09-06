class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=0,rowe=matrix.size()-1;
        int ans=0;
        while(rows<=rowe){
            int mid=(rows+rowe)/2;
            if(matrix[mid][0]<=target and target<=matrix[mid][matrix[mid].size()-1]){
                ans=mid;
                break;
            }
            else if(matrix[mid][0]>target){
                rowe=mid-1;
            }else{
                rows=mid+1;
            }
        }
         
            int st=0,end=matrix[0].size()-1;
            while(st<=end){
                int mid=(st+end)/2.0;
                if(matrix[ans][mid]==target)
                    return true;
                else if(matrix[ans][mid]>target){
                    end=mid-1;
                }else{
                    st=mid+1;
                }
            }
        
        return false;
    }
};
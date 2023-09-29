class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        int st=0,end=n-1;
        while(st<m and end>=0){
            if(matrix[st][end]==target) return true;
            else if(matrix[st][end]>target) end--;
            else st++;
        }
        return false;
    }
};
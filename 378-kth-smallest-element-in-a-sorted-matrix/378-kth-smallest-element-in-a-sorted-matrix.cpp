class Solution {
public:
    int lessthanequal(vector<vector<int>>& matrix,int target){
        int rows = matrix.size(),
			cols = matrix[0].size(),
            row = 0, col = cols - 1;
        int cnt=0;
        while (row < rows && col > -1) {
            int cur = matrix[row][col];
            if (target >= cur) {
                row++;
                cnt+=col+1;
            }
            else col--;
        }
        
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int min=matrix[0][0],max=matrix[n-1][n-1];
        while(min!=max){
            int mid=min+(max-min)/2;
            int cnt=lessthanequal(matrix,mid);
            if(cnt<k){
                min=mid+1;
            }else
                max=mid;
        }
        return min;
    }
};
// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
   public:
   int helper(vector<vector<int>> &matrix,int r,int c,int xs,int ys,int xd,int yd,vector<vector<int>> &vis)
   {
        if(r<0||c<0||r>=matrix.size()||c>=matrix[0].size()||matrix[r][c]==0||vis[r][c]==1){
           return -1;
        }
        vis[r][c]=1;
        if(r==xd and c==yd){
           vis[r][c]=0;
           return 0;
        }
        int left=-1,right=-1,up=-1,down=-1;
        up=helper(matrix,r-1,c,xs,ys,xd,yd,vis);
        down=helper(matrix,r+1,c,xs,ys,xd,yd,vis);
        left=helper(matrix,r,c-1,xs,ys,xd,yd,vis);
        right=helper(matrix,r,c+1,xs,ys,xd,yd,vis);
        vis[r][c]=0;
        int ans=max(up,max(down,max(left,right)));
        return ans!=-1?ans+1:ans;
   }
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        vector<vector<int>> vis(matrix.size(),vector<int>(matrix[xs].size(),0));
        return helper(matrix,xs,ys,xs,ys,xd,yd,vis);
    }
};
// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends
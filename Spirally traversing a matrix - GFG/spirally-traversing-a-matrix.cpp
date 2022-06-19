// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > mat, int r, int c) 
    {
        // code here 
        int cnt=1;
        vector<int>v;
        int rows=0,rowe=r-1,cols=0,cole=c-1;
        while(rows<=rowe and cols<=cole){
            for(int i=cols;i<=cole;i++){
                v.push_back(mat[rows][i]);
            }rows++;
            if(rows>rowe)
            break;
            for(int i=rows;i<=rowe;i++){
                v.push_back(mat[i][cole]);
            }cole--;
            if(cols>cole)
            break;
            for(int i=cole;i>=cols;i--){
                v.push_back(mat[rowe][i]);
            }rowe--;
            if(rows>rowe)
            break;
            for(int i=rowe;i>=rows;i--){
                v.push_back(mat[i][cols]);
            }cols++;
        }
        return v;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
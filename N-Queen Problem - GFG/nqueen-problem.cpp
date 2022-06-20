// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
vector<vector<int>> v;
int issafe(int **board,int row,int col,int n){
    for(int i=0;i<=col;i++){
        if(board[row][i]==1){
            return 0;
        }
    }
    for(int i=0;i<=row;i++){
        if(board[i][col]){
            return 0;
        }
    }
    for(int i=row-1,j=col-1;i>=0 && j>=0;){
        if(board[i--][j--]==1){
            return 0;
        }
    }
    for(int i=row-1,j=col+1;i>=0 && j<n;){
        if (board[i--][j++]==1)
        {
            return 0;
        }
    }
    return 1;
}
int cnt=0;
int nqueen(int **board,int *ans,int st,int row,int n){
    if(row==n){
        if(st==n){
            vector<int> temp;
        for(int i=0;i<st;i++){
            temp.push_back(ans[i]);
        }
        v.push_back(temp);
        cnt++;
        }
        return 1;
    }
   
    for(int i=0;i<n;i++){
        if(issafe(board,row,i,n)){
            board[row][i]=1;
            ans[st]=i+1;
            int check=nqueen(board,ans,st+1,row+1,n);
            board[row][i]=0;
            ans[st]=0;
            //ans[st]=0;
        }
    }
    return 0;
}

    

    vector<vector<int>> nQueen(int n) {
        // code here
        int i,*ans,j;
    int **board=(int**)malloc(n * sizeof(int*));
    ans=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        board[i]=(int*)malloc(n * sizeof(int));
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            board[i][j]=0;
        }
    }
    
    int check=nqueen(board,ans,0,0,n);
    return v;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends
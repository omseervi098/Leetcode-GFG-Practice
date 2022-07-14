// { Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}
// } Driver Code Ends


int count(int mat[MAX][MAX],int mid,int n){
    int i=0,j=n-1,ans=0;
    while(i<n and j>=0){
        if(mid>=mat[i][j]){
            ans+=j+1;
            i++;
        }else
            j--;
    }return ans;
}
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    int min=mat[0][0],max=mat[n-1][n-1];
    while(min!=max){
        int mid=min+(max-min)/2;
        int cnt=count(mat,mid,n);
        if(cnt<k){
            min=mid+1;
        }else{
            max=mid;
        }
    }return max;
}

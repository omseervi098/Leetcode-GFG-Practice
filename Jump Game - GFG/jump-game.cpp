// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int helper(int A[],int st,int end){
        if(st==end) return 1;
        if(st>end) return 0;
        for(int i=1;i<=A[st];i++){
          int sans=helper(A,st+i,end);
          if(sans==1)return 1;
        }
        return 0;
    }
    int canReach(int A[], int N) {
        return helper(A,0,N-1);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}  // } Driver Code Ends
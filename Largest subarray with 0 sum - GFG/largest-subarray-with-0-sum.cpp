// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        int sum=0;
        unordered_map<int,int> map;
        map[0]=-1;
        int len=0;
        for(int i=0;i<n;i++){
            sum+=A[i];
            if(map.count(sum)){
                int k=i-map[sum];
                len=max(len,k);
            }else{
                map[sum]=i;
            }
           //15 -2 2 -8 1 7 10 23
           //15 13 15 7 8 15 25 48
        }
        return len;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends
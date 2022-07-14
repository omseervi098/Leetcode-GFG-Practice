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
        int j=0,sum=0;
        vector<int> presum;
        for(auto it:A){
            sum+=it;
            presum.push_back(sum);
        }
        unordered_map<int,int> map;
        map[0]=-1;
        int len=0;
        if(sum==0)return n;
        for(int i=0;i<n;i++){
            if(map.count(presum[i])){
                int k=i-map[presum[i]];
                len=max(len,k);
            }else{
                map[presum[i]]=i;
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
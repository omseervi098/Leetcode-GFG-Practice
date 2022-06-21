// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        vector<int> maxa;
        int j=0,mx=INT_MIN;
        deque<int> dq;
        for(int i=0;i<k;i++){
            if(i==0){
                dq.push_back(i);
                continue;
            }
            while(dq.size()!=0 and arr[i]>arr[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        j=1;
        for(int i=k;i<=n;i++){
            maxa.push_back(arr[dq.front()]);
            while(dq.size()!=0  and dq.front()<=i-k){
                dq.pop_front();
            }
             while(dq.size()!=0 and arr[i]>arr[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return maxa;
        
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends
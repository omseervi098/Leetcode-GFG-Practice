// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        long long int lsum=0;
        long long int rsum=0;
        long long int tsum=0;
        for(int i=0;i<n;i++)
           tsum+=a[i];
        for(int i=0;i<n;i++){
            rsum=tsum-lsum-a[i];
            if(lsum==rsum)
            return i+1;
            lsum+=a[i];
        }
        //cout<<lsum<<" "<<rsum<<endl;
      return -1;
    }

};

// { Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
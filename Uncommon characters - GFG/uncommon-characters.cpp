// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
        string UncommonChars(string A, string B)
        {
            if(A==B)return "-1";
            int map[26]={0};
            int map1[26]={0};
            for(auto it:A)
                map[it-'a']=1;
            for(auto it:B){
                if(map[it-'a']==1)
                   map[it-'a']=0;
                map1[it-'a']=1;
            }
            for(auto it:A){
                if(map1[it-'a']==1)
                map1[it-'a']=0;
            }
            int i;
            for( i=0;i<26;i++){
                if(map[i]!=map1[i]){
                    break;
                }
            }
            if(i==26)return "-1";
            string temp="";
            
            for(int i=0;i<26;i++){
                if(map[i]!=0 ||map1[i]!=0){
                    temp+=i+'a';
                }                    
    
            }
            return temp;
        }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution ob;
        cout<<ob.UncommonChars(A, B);
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
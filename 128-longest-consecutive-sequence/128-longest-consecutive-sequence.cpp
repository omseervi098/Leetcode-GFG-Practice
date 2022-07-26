class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int mxlen=0;
       for(int i=0;i<n;i++){
        int st=arr[i];
        int k=i;
          int temp=0;
        while(i<n-1 and (arr[i]+1==arr[i+1]||arr[i]==arr[i+1])){
            if(arr[i]==arr[i+1]) temp++;
            i++;
        }
        cout<<temp<<endl;
        if((i-k-temp)+1>=mxlen){
            mxlen=(i-k-temp)+1;
            cout<<mxlen<<endl;
        }   
        // 0 1 1 2
    }
    return mxlen;
    }
};
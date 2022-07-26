class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
       int n=arr.size();
       unordered_map<int,int> map; 
       unordered_map<int,bool> m;
       for(int i=0;i<n;i++)
       {
          m[arr[i]]=true;
          map[arr[i]]=i;
       }
       int mxst=0,mxlen=0,size=0;
       for(int i=0;i<n;i++){
           size=0;
           if(m[arr[i]]){
              int st=arr[i];
              size++;
              int j=st+1;
              while(m.count(j)){
                 m[j]=false;
                 size++;
                 j++;
              }
              j=st-1;
              while(m.count(j)){
                 st=j;
                 m[j]=false;
                 size++;
                 j--;
              }
              if(size>mxlen){
                 mxst=st;
                 mxlen=size;
              }
              if(size==mxlen){
                 if(map[st]<map[mxst]){
                     mxst=st;
                     mxlen=size;
                 }
               }
           }
       }
       return mxlen;
    }
};
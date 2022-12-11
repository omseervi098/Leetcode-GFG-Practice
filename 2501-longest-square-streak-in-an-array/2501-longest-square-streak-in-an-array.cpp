#define ll long long int;
class Solution {
public:
  int longestSquareStreak(vector<int>& arr) {
      sort(arr.begin(), arr.end());
      int ans=0,count=0;
      map<int,int> mp;
      for(auto it:arr) mp[it]=1;
      for (int i = 0; i < arr.size()-1; i++) {
          int cnt=1;
          long long st=arr[i];
          while(st<=(INT_MAX)/2){
              st*=st;
              if(mp[(int)st]==1) cnt++;
              else break;
          }ans=max(ans,cnt);
      }
      if(ans==1)
          return -1;
      return ans;
    }
    
};
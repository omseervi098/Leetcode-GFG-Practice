#define ll long long int;
class Solution {
public:
  int longestSquareStreak(vector<int>& arr) {
      sort(arr.begin(), arr.end());
      int ans=0;
      unordered_set<int> mp;
      for(auto it:arr) mp.insert(it);
      for (int i = 0; i < arr.size()-1; i++) {
          int cnt=1;
          long long st=arr[i];
          while(st<=(INT_MAX)/2 and mp.count(st)==1){
              st*=st;
              cnt++; 
          }ans=max(ans,cnt-1);
      }
      if(ans==1)
          return -1;
      return ans;
    }
    
};
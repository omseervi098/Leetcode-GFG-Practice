#define ll long long int;
class Solution {
public:
  int longestSquareStreak(vector<int>& arr) {
      sort(arr.begin(), arr.end());
      int ans=0;
      unordered_set<int> mp;
      for(auto it:arr) mp.insert(it);
      for (auto i:arr) {
          int cnt=1;
          long long st=i;
          while(st<=(INT_MAX)/2 and mp.count(st)==1){
              st*=st;
              cnt++; 
          }
          ans=max(ans,cnt-1);
      }
      return ans==1?-1:ans;
    }
    
};
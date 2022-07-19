class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& arr) {
        unordered_map<int,int> m;
        for(int i=0;i<nums1.size();i++){
            m[nums1[i]]=i;
        }
        
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(m.count(arr[i])>0)
                m[arr[i]]=i;
        }
        vector<int> ans(n,-1);
      stack<int> s;
      for(int i=n-1;i>=0;i--)
      {
          if(s.empty()){
              s.push(arr[i]);
              continue;
          }
          if(!s.empty() and arr[i]<s.top()){
              ans[i]=s.top();
              s.push(arr[i]);
          }else if(!s.empty() and arr[i]>=s.top()){
              while(!s.empty() and arr[i]>=s.top())s.pop();
              if(!s.empty())
                  ans[i]=s.top();
              s.push(arr[i]);
          }
      }
        vector<int> fans(nums1.size());
        for(int i=0;i<nums1.size();i++){
            fans[i]=ans[m[nums1[i]]];
        }
        return fans;
      
    }
};
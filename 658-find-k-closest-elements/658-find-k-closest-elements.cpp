class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(),arr.end());
        int fid=find(arr.begin(),arr.end(),x)-arr.begin();
        vector<int> ans;
        if(fid==arr.size()){
            if(x<arr[0]){
                int i=0;
                while(i<k) ans.push_back(arr[i++]);
                return ans;
            }else if(x>arr[arr.size()-1]){
                int i=0;
                int skip=arr.size()-k;
                for(;i<arr.size();i++){
                    if(skip<=0){
                        ans.push_back(arr[i]);
                    }else{
                        skip--;
                    }
                }
                return ans;
            }else{
                int s,e;
                for(int i=0;i<arr.size();i++){
                    if(arr[i]<x)
                        s=i;
                }
                for(int i=arr.size()-1;i>=0;i--){
                    if(arr[i]>x){
                        e=i;
                    }
                }
               int st=s,end=e; priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            for(int i=0;i<arr.size();i++) pq.push({abs(arr[i]-x),i});
            while(pq.size() && k>0){
                ans.push_back(arr[pq.top().second]);
                k--;
                pq.pop();
            }
            sort(ans.begin(),ans.end());
            return ans;
            }
        }else{
            int idx=fid;
            int st=idx-1,end=idx+1;
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            for(int i=0;i<arr.size();i++) pq.push({abs(arr[i]-arr[idx]),i});
            while(pq.size() && k>0){
                ans.push_back(arr[pq.top().second]);
                k--;
                pq.pop();
            }
            sort(ans.begin(),ans.end());
            return ans;
        }
        return {};
    }
};
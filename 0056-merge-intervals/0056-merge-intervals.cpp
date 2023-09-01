class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> v;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int st=arr[i][0],end=arr[i][1];
            if(!v.empty() and v.back()[1]>=end) continue;
            for(int j=i+1;j<n;j++){
                if(arr[j][0]<=end)
                    end=max(arr[j][1],end);
                else break;
            }
            v.push_back({st,end});
        }
        return v;
    }
};
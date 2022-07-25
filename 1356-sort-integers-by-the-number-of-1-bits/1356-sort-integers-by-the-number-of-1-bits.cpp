class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<vector<int>> v;
        for(auto it:arr){
            v.push_back({__builtin_popcount(it),it});
        }
        sort(v.begin(),v.end());
        int k=0;
        for(auto it:v){
            arr[k++]=it[1];
        }
        return arr;
    }
};
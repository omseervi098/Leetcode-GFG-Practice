class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> arr(pref.size(),0);
        int k=pref.size()-1;
        for(int i=k;i>0;i--){
            arr[k--]=pref[i]^pref[i-1];
        }
        arr[k]=pref[0];
        return arr;
    }
};
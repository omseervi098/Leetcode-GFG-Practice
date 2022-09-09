class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        if(a[0]!=b[0]){
            return a[0]>b[0];
        }
        return a[1]<b[1];
    }
    int numberOfWeakCharacters(vector<vector<int>>& prop) {
        sort(prop.begin(),prop.end(),comp);
        int mx=INT_MIN;
        int ans=0;
        for(auto it:prop){
            if(it[1]>=mx){
                mx=it[1];
            }else
                ans++;
        }
        return ans;
    }
};
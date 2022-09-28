class Solution {
public:
    int helper(int x){
        if(x==1) return 0;
        if(x&1) return 1+helper(3*x+1);
        else return 1+helper(x/2);
        return 0;
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> h;
        for(int i=lo;i<=hi;i++)
            h.push_back({helper(i),i});
        sort(h.begin(),h.end());
        return h[k-1].second;
    }
};
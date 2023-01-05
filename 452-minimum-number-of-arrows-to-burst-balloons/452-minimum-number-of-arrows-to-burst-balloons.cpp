class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& p) {
        sort(p.begin(),p.end());
        int n=p[0][1],ans=1;
        for(int i=1;i<p.size();i++){
            if(p[i][0]>n){
                ans++;
                n=p[i][1];
            }
            n=min(p[i][1],n);
        }
        return ans;
    }
};
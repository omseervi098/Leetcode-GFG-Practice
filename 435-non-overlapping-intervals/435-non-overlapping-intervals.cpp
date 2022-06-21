class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& inter) {
        sort(inter.begin(),inter.end());
        int cnt=0;
        int end=inter[0][1];
        for(int i=1;i<inter.size();i++){
            if(end>inter[i][0]){
                cnt++;
                end=min(end,inter[i][1]);
            }else
                end=inter[i][1];
        }return cnt;
    }
};
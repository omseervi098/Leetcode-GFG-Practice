class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& p) {
        int mx=INT_MAX,mxidx=-1;
        for(int i=0;i<p.size();i++){
            if(p[i][0]==x||p[i][1]==y){
                int k=abs(p[i][0]-x)+abs(p[i][1]-y);
                if(k<mx){
                    mx=k;
                    mxidx=i;
                }
            }
        }return mxidx;
    }
};
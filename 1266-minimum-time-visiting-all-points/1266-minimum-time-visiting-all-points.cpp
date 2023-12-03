class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int tm=0;
        for(int i=1;i<points.size();i++){
            int y=abs(points[i][1]-points[i-1][1]),x=abs(points[i][0]-points[i-1][0]);
            tm+=abs(y-x)+min(y,x);
        }
        return tm;
    }
};
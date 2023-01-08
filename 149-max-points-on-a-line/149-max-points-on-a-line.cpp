class Solution {
public:
    int maxPoints(vector<vector<int>>& p) {
        unordered_map<double,int> m1,m2;
        int dupx=1,dupy=1,mx=0;
        for(int i=0;i<p.size();i++){
            dupx=dupy=1;
            for(int j=i+1;j<p.size();j++){
                int ans=0,x2=p[j][0],x1=p[i][0],y2=p[j][1],y1=p[i][1];
                int dy=y2-y1,dx=x2-x1;
                if(x1==x2){
                    dupx++;
                    if(y1==y2)
                    dupy++;
                }
                else{
                    m1[double(y2-y1)/double(x2-x1)]+=1;
                }
            }
            mx=max(mx,dupx);
            for(auto it:m1){
                mx=max(mx,it.second+dupy);
            }
            m1.clear();
        }

        return mx;
    }
};
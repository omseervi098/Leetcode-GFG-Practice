class Solution {
public:
    int garbageCollection(vector<string>& ga, vector<int>& t) {
        unordered_map<int,int> g,m,p;
        for(int i=ga.size()-1;i>=0;i--){
            m[i]=m[i+1]; g[i]=g[i+1];p[i]=p[i+1];
            for(auto j:ga[i]){
                if(j=='M') m[i]++;
                else if(j=='P') p[i]++;
                else if(j=='G') g[i]++;
            }
        }
        int gt=0,mt=0,pt=0,i=0;
        for(i=0;i<ga.size()-1;i++){
            gt+=g[i]-g[i+1];
            mt+=m[i]-m[i+1];
            pt+=p[i]-p[i+1];
            if(g[i+1]>0) gt+=t[i];
            if(m[i+1]>0) mt+=t[i];
            if(p[i+1]>0) pt+=t[i];
        }
        if(g[i]>0) gt+=g[i];
        if(m[i]>0) mt+=m[i];
        if(p[i]>0) pt+=p[i];
        return gt+mt+pt;
    }
};
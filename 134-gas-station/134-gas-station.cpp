class Solution {
public:
    int canCompleteCircuit(vector<int>& g, vector<int>& c)     {
        int n=g.size(),total=0,srpl=0,start=0;
        for(int i=0;i<g.size();i++){
            total+=g[i]-c[i];
            srpl+=g[i]-c[i];
            if(srpl<0){
                srpl=0;
                start=i+1;
            }
        }
        return total<0?-1:start;
    }
};
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        sort(inter.begin(),inter.end());
        int res=0;
        for(int i=1;i<inter.size();i++){
            if(inter[i][0]<=inter[res][1]){
                inter[res]={min(inter[i][0],inter[res][0]),max(inter[i][1],inter[res][1])};
            }else{
                res++;
                inter[res]=inter[i];
            }
        }
        inter.resize(res+1);
        return inter;
        
    }
};
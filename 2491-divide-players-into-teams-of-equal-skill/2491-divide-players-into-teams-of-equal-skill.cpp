class Solution {
public:
    long long dividePlayers(vector<int>& s) {
        sort(s.begin(),s.end());
        long long  st=0,end=s.size()-1;
        set<long long> set;
        vector<pair<int,int>> v;
        while(st<end){
            v.push_back({s[st],s[end]});
            set.insert(s[st++]+s[end--]);
            
        }
        if(set.size()==1){
            long long sm=0;
            for(auto it:v){
                sm+=it.first*it.second;
            }
            return sm;
        }else return -1;
    }
};
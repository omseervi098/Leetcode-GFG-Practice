class Solution {
public:
    long long dividePlayers(vector<int>& s) {
        sort(s.begin(),s.end());
        long long  st=0,end=s.size()-1,ans=0,p=-1;
        vector<pair<int,int>> v;
        while(st<end){
            v.push_back({s[st],s[end]});
            ans+=s[st]*s[end];
            if(p==-1){
                p=s[st++]+s[end--];
            }
            else{
                int check=s[st++]+s[end--];
                if(check!=p){
                    return -1;
                }else p=check;
            }
            
        }
        return ans;
    }
};
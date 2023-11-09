class Solution {
public:
    int countHomogenous(string s) {
        int cnt=1,ans=0,mod=1e9+7;
        for(int i=1;i<=s.size();i++){
            if(s[i]==s[i-1]){
                cnt++;
            }else{
                ans+=(cnt*1ll*(cnt+1)/2)%mod;
                cnt=1;
            }
        }
        return ans;
    }
};
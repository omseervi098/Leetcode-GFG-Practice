class Solution {
public:
    int numberOfWays(string c) {
        // 0 1 2 2 2 3 3 4
        // 4 3 2 2 2 1 1 0
        // 0 0 0 1 1 2 2
        // 2 2 2 1 1 0 0
        
        const int n=c.size(),mod=1e9+7;
        vector<int> pre(n+1,0),suf(n+1,0);
        for(int i=0;i<n;i++){
            if(c[i]=='S') pre[i+1]=pre[i]+1;
            else pre[i+1]=pre[i];
        }
        for(int i=n-1;i>=0;i--){
            if(c[i]=='S') suf[i]=suf[i+1]+1;
            else suf[i]=suf[i+1];
        }
        if(pre[n]%2==1 || pre[n]==0) return 0;
        if(pre[n]==2) return 1;
        long long int cnt=1;
        for(int i=0;i<=n;i++){
            if(pre[i]%2==0 and pre[i]>0){
                int temp=pre[i],j=i;
                while(i<n and temp==pre[i]) i++;
                if(suf[i]!=0)
                    cnt=(cnt%mod*(i-j))%mod;
            }
        }
        return cnt%mod;
    }
};
class Solution {
public:
    int bestClosingTime(string c) {
        vector<int> pre(c.size()+1);
        int cntofy=0;
        for(auto it:c) {
            if(it=='Y') cntofy++;
        }
        pre[0]=cntofy;
        int cntofn=0;
        for(int i=1;i<=c.size();i++){
            if(c[i-1]=='Y'){
                pre[i]=cntofy+cntofn-1;
                cntofy--;
            }else{
                cntofn++;
                pre[i]=cntofy+cntofn;
            }
        }
        int mn=INT_MAX,mnidx=0;
        for(int i=0;i<pre.size();i++){
            cout<<pre[i]<<" ";
            if(pre[i]<mn){
                mn=pre[i];
                mnidx=i;
            }
        }
        return mnidx;
    }
};
class Solution {
public:
    
    void dfs(int n,int k,int st,int &num,vector<int> &v){
        if(n==1){
            v.push_back(num);
            return;
        }
        if(st+k<=9){
            int temp=num*10+st+k;
            dfs(n-1,k,st+k,temp,v);
        }
        if(st+k!=st-k and st-k>=0){
            int temp=num*10+st-k;
            dfs(n-1,k,st-k,temp,v);
        }     
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> v;
        for(int i=1;i<=9;i++){
            
            dfs(n,k,i,i,v);
        }
        return v;
    }
};
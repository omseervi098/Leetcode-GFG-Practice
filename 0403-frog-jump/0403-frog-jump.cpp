class Solution {
    unordered_map<int,int> s;
public:
    bool helper(int k,int st,int end,vector<int> &stones,vector<vector<int>> &dp){
        //Boundary Condition
        if(st>=end){
            return true;
        }
        if(dp[st][k]!=-1) return dp[st][k];
        //3 Options k-1,k,k+1
        bool a=false,b=false,c=false;
        cout<<stones[st]<<" "<<k<<endl;
        if(s.count(stones[st]+k)!=0) 
            b=helper(k,s[stones[st]+k],end,stones,dp);
        if(s.count(stones[st]+k+1)!=0)
            c=helper(k+1,s[stones[st]+k+1],end,stones,dp);
        if(k>1 and s.count(stones[st]+k-1)!=0)
            a=helper(k-1,s[stones[st]+k-1],end,stones,dp);
        
        return dp[st][k]=a || b || c;
    }
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        vector<vector<int>> dp(n,vector<int>(2000,-1));
        for(int i=0;i<stones.size();i++)  s[stones[i]]=i;
        int k=1;
        if(s.count(stones[0]+k)==0) return false;
        return helper(1,1,stones.size()-1,stones,dp);
        // 0 1 3 5 6 8 12 17
        // 0 1 2 2 1 2 4  5
        // 0 1 2 2 3   4  5
    } 
};
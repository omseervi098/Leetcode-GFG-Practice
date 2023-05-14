// class Solution {
    
//     public:
//     int maxScore(vector<int>& nums) {
//         //wrong approach because incase if we choose whatever giving us max gcd then it may happen even after that we can get less max overall gcd for that we need to use recursion --> memoization --> DP
//         int n=nums.size(); 
//         int sm=0;
//         unordered_map<int,int> visited;
//         for(int i=0;i<n-1;i++){
//             int mx=0,mxnum=0;
//             if(visited.count(nums[i])>0){
//                 visited[nums[i]]--;
//                 if(visited[nums[i]]<=0) visited.erase(nums[i]);
//                 continue;
//             }
//             for(int j=i+1;j<n;j++){
//                 if(visited.count(nums[j])>0) {
//                     visited[nums[j]]--;
//                      if(visited[nums[j]]<=0) visited.erase(nums[j]);
//                      continue;
//                 }
//                 int tmp=__gcd(nums[i],nums[j]);
//                 if(tmp>mx){
//                     mx=tmp;
//                     mxnum=nums[j];
//                 }
                
//             }
//             cout<<nums[i]<<" "<<mxnum<<endl;
//             visited[mxnum]++;
//             sm+=(i+1)*mx;
//         }
        
//         return sm;
//     }
// };
class Solution {
public:
    int n;
    int solve(vector<int>& nums, vector<bool>& visited, int operationNo, unordered_map<vector<bool>,int>& mp)
    {
        if(mp.find(visited) != mp.end()) return mp[visited];
        int maxScore=0;
        for(int i=0;i<n-1;i++)
        {
            if(visited[i]==true) continue;
            for(int j=i+1;j<n;j++)
            {
                if(visited[j]==true) continue;
                visited[i]=true;
                visited[j]=true;
                int currScore=operationNo* __gcd(nums[i],nums[j]);
                int remainingScore=solve(nums,visited,operationNo+1,mp);
                maxScore=max(maxScore,currScore+remainingScore);
                //backtracking:
                visited[i]=false;
                visited[j]=false;
            }
        }
        return mp[visited]=maxScore;

    }
    int maxScore(vector<int>& nums) {
        n=nums.size();
        vector<bool> visited(n,false);
        unordered_map<vector<bool>,int> mp;
        return solve(nums,visited,1,mp);
    }
};
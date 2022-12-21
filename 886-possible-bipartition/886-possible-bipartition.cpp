class Solution {
public:
    bool isbipartite(int source, unordered_map<int,vector<int>>& ump,      vector<int>& color,vector<int>& vist)
    {
         queue<int> q;
         q.push(source);
         vist[source] = 1;
         bool ans = true;
         while(!q.empty())
         {
             auto x = q.front();
             q.pop();

             for(auto y:ump[x])
             {
                 if(vist[y] == -1)
                 {
                     vist[y] = 1;
                     color[y] = !color[x];
                     q.push(y);
                 }
                 else if(color[x] == color[y])
                 {  
                     ans = false;
                 }
             }
         }
         
         return ans;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) 
    {
        unordered_map<int,vector<int>> ump;
        int N = dislikes.size();
        vector<int> color(n+1,0);
        vector<int> vist(n+1,-1);
        for(int i=0;i<N;i++)
        {
            ump[dislikes[i][0]].push_back(dislikes[i][1]);
            ump[dislikes[i][1]].push_back(dislikes[i][0]);
        }

        bool ans = true;
        for(int i=1;i<=n;i++)
        {
            int source = i;
            ans = isbipartite(source,ump,color,vist);
            
            if(ans == false)
            break;
        }
        return ans;
    }
};
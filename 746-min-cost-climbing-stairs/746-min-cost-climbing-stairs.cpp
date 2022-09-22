class Solution {
public:
    int helper(int* arr,int n,int* visited){
        if(n<2)return 0;
        if(visited[n]!=-1)
            return visited[n];
        int a=arr[0]+helper(arr+1,n-1,visited);
        int b=arr[1]+helper(arr+2,n-2,visited);
        visited[n]=min(a,b);
        return min(a,b);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int arr[cost.size()];
        int k=0;
        for(auto it:cost){
            arr[k++]=it;
        }int visited[k+1];
        for(int i=0;i<=k;i++)
            visited[i]=-1;
        return helper(arr,k,visited);
    }
};
class Solution
{
public:
    void subsetSum(vector<int> & arr,vector<int>  tmp, int n, int i, int sum,vector<vector<int>> &v)
    {
        if (i == n)
        {
            if (sum == 0){
                for(auto it:tmp)
                    cout<<it<<" ";
                cout<<endl;
                v.push_back(tmp);
                return;
            }else
                return;
        }
        if (sum - arr[i] >= 0){
            tmp.push_back(arr[i]);
            subsetSum(arr, tmp,n, i , sum - arr[i],v);
            tmp.pop_back();
        }
        subsetSum(arr,tmp, n, i + 1, sum,v);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> v;
        vector<int> tmp;
        subsetSum(candidates,tmp,candidates.size(),0,target,v);
        return v;
    }
};
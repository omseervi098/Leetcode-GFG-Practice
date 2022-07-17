class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> m;
        int n=numbers.size();
        for(int i=0;i<n;i++){
            int k=target-numbers[i];
            if(m.count(k)>0){
                return {m[k]+1,i+1};
            }m[numbers[i]]=i;
        }return {-1};
    }
};
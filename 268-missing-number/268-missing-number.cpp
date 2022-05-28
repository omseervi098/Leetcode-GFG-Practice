class Solution {
public:
    int missingNumber(vector<int>& a) {
        int sum=accumulate(a.begin(), a.end(), 0);
        int n=a.size();
        int sumofn=((n+1)*n)/2;
        return sumofn-sum;
    }
};
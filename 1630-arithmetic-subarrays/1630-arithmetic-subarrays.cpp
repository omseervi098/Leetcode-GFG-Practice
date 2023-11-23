class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& arr, vector<int>& l, vector<int>& r) {
        vector<bool> v;
        for(int  i=0;i<l.size();i++){
            int a=l[i],b=r[i];
            unordered_map<int, int> hm;
            int smallest = INT_MAX, second_smallest = INT_MAX,j=0;
            for (j=a; j<=b; j++) {
                if (arr[j] < smallest) {
                    second_smallest = smallest;
                    smallest = arr[j];
                }
                else if (arr[j] != smallest && arr[j] < second_smallest)
                    second_smallest = arr[j];
                if (hm.count(arr[j])==0)
                    hm[arr[j]]++;
            }
            if(second_smallest==INT_MAX) second_smallest=smallest;
            int diff = second_smallest - smallest;
            for (j=a;j<b;j++) {
                cout<<second_smallest<<" ";
                if (hm.count(second_smallest)==0)
                    break;
                second_smallest += diff;
            }cout<<j<<endl;
            if(j==b) v.push_back(true);
            else v.push_back(false);
        }
        return v;
    }
};
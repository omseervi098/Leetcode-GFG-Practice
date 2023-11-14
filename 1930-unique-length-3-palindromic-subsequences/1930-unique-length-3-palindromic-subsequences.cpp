class Solution {
    // Function to perform queries in a range
    long long query(int start, int end, int left, int right,int node, long long seg[])
    {
        // No overlap
        if (end < left || start > right) {
            return 0;
        }
        // Totally Overlap
        else if (start >= left && end <= right) {
            return seg[node];
        }
        // Partial Overlap
        else {
            int mid = (start + end) / 2;
            // Finding the Answer
            // for the left Child
            long long leftChild = query(start, mid, left,right, 2 * node, seg);
            // Finding the Answer
            // for the right Child
            long long rightChild = query(mid + 1, end, left,right, 2 * node + 1, seg);
            // Combining the BitMasks
            return (leftChild | rightChild);
        }
    }
    // Building the Segment Tree
    void build(int left, int right, int node, string &ar,long long seg[])
    {
        if (left == right) {
            // Building the Initial BitMask
            seg[node] = (1LL << (ar[left]-'a'+1));
            return;
        }
        int mid = (left + right) / 2;
        // Building the left seg tree
        build(left, mid, 2 * node, ar, seg);
        // Building the right seg tree
        build(mid + 1, right, 2 * node + 1, ar, seg);
        // Forming the BitMask
        seg[node] = (seg[2 * node] | seg[2 * node + 1]);
    }
    // Utility Function to answer the queries
    int getDistinctCount(int l,int r,string &s, long long seg[], int n)
    {

        long long tempMask = query(0, n - 1, l, r, 1, seg);
        int countOfBits = 0;
        // Counting the set bits which denote the
        // distinct elements
        for (int i = 26; i >= 0; i--) {
            if (tempMask & (1LL << i)) {
                countOfBits++;
            }
        }
        // remove l and r range 
        return countOfBits;
    }
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        long long seg[4*n];
        build(0, n - 1, 1,s, seg);
        getDistinctCount(2,5,s,seg,n);
        unordered_map<char,int> lastidx;
        for(int i=n-1;i>=0;i--){
            if(lastidx.count(s[i])==1) continue;
            else lastidx[s[i]]=i;
        }
        int cnt=0;
        unordered_set<char> set;
        for(int i=0;i<n;i++){
            if(set.count(s[i])>0) continue;
            if(lastidx[s[i]]==i){
                continue;
            }else{
                int t=getDistinctCount(i+1,lastidx[s[i]]-1,s,seg,n);
                cout<<i<<" "<<lastidx[s[i]]<<" "<<t<<endl;
                cnt+=t;
            }
            set.insert(s[i]);
        }
        return cnt;
    }
};
class Solution {
public:
    bool isprime(int n)
    {
        if (n <= 1)
            return false;
        if (n <= 3)
            return true;
        if (n % 2 == 0 || n % 3 == 0)
            return false;
        for (int i = 5; i * i <= n; i = i + 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        if(right-left==0) return {-1,-1};
        int mn=INT_MAX;
        vector<int> v(2);
        vector<bool> a(right-left+1);
        vector<int> m;
        for(int i=left;i<=right;i++){
            a[i-left]=isprime(i);
            if(isprime(i)==true){
                m.push_back(i);
            }
        }
        if(m.size()<=1) return {-1,-1};
        for(int i=0;i<m.size()-1;i++){
            int j=i+1;
            if((m[j]-m[i])<mn){
                mn=(m[j]-m[i]);
                v[0]=m[i];
                v[1]=m[j];
            } 
        }
        if(mn==INT_MAX) return {-1,-1};
        return v;
    }
};
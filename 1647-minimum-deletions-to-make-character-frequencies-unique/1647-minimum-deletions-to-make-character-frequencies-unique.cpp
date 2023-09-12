class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> m,m1;
        for(auto i:s) m[i]++;
        vector<int> v;
        for(auto i:m) {v.push_back(i.second);m1[i.second]++;}
        sort(v.begin(),v.end());
        int cnt=0;
        for(int i=1;i<v.size();i++){
            if(v[i-1]==v[i]){
                int k=v[i]-1;
                while(k!=0 and m1.count(k)>0) k--;
                cnt+=v[i]-k;
                m1[k]++;
            }
        }
        return cnt;
    }
};
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> v;
        for(int i=0;i<A.size();i++){
            int cnt=0;
            unordered_map<int,int> mp;
            for(int j=0;j<=i;j++){
                mp[A[j]]+=1;
                mp[B[j]]+=1;
            }
            for(auto i:mp){
                if(i.second>1){
                    cnt++;
                }
            }
            v.push_back(cnt);
        }
        return v;
    }
};
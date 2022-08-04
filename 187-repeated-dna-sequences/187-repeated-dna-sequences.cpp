class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> m;
        int n=s.size();
        vector<string> v;
        for(int i=0;i<n;i++){
            string temp=s.substr(i,10);
            m[temp]+=1;
        }
        for(int i=0;i<n;i++){
            string temp=s.substr(i,10);
            if(m.count(temp)>0 and m[temp]>1){
                v.push_back(s.substr(i,10));
                m.erase(temp);
            }
        }
        return v;
    }
};
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> m;
        unordered_map<string,bool> m1;
        int n=s.size();
        vector<string> v;
        for(int i=0;i<n;i++){
            string temp=s.substr(i,10);
            if(m.count(temp)>0){
                v.push_back(temp);
                m.erase(temp);
            }else if(m.count(temp)==0 and !m1[temp]){
                m[temp]+=1;
                m1[temp]=true;
            }
        }
        return v;
    }
};
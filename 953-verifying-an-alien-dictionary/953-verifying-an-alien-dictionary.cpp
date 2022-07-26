class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<int,int> map;
        for(int i=0;i<order.size();i++)
            map[order[i]]=i;
        for(int i=0;i<words.size()-1;i++){
            string s1=words[i];
            string s2=words[i+1];
            for(int i=0;i<min(s1.size(),s2.size());i++){
                if(s1[i]==s2[i]) continue;
                if(map[s1[i]]>map[s2[i]])
                   return false;
                else break;
            }
            if(s1.size()>s2.size() and map[s1[s2.size()-1]]>=map[s2[s2.size()-1]]) 
                return false;
        }
        return true;
    }
};
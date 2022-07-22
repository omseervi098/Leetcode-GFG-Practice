class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> m;
        for(auto it:t)
            m[it]+=1;
        for(auto it:s)
            m[it]-=1;
        for(auto it:t){
            if(m.count(it)>0){
                if(m[it]>0){
                    return it;
                }
            }
        }
        return '0';
    }
};
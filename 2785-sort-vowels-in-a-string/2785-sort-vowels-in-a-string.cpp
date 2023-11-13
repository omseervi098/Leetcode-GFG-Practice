class Solution {
public:
    string sortVowels(string s) {
        map<char,int> mp;
        vector<char> v={'A','E','I','O','U','a','e','i','o','u'};
        for(auto it:s) if(find(v.begin(),v.end(),it)!=v.end()) mp[it]++;
        v.clear();
        for(auto it:mp) v.push_back(it.first);
        string newstring;
        int k=0;
        for(auto i:s){
            if(mp.count(i)==1){
                if(mp[v[k]]>1){
                    newstring+=v[k];
                    mp[v[k]]--;
                }else if(mp[v[k]]==1){
                    newstring+=v[k];
                    mp[v[k++]]--;
                }
            }else{
                newstring+=i;
            }
        }
        return newstring;
        
    }
};
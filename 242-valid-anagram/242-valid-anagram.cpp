class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>map;
        for(auto it:s){
            map[it]+=1;
        }
        for(auto it:t){
            if(map.count(it)>0)
                map[it]-=1;
            else
                map[it]+=1;
        }
        for(auto it:map){
            if(it.second!=0)
                return false;
        }
        return true;
    }
};
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>map;
        for(int i=0;i<magazine.size();i++){
            map[magazine[i]]+=1;
        }
        bool check=false;
        for(int i=0;i<ransomNote.size();i++){
            if(map.count(ransomNote[i])>0){
                check=true;
                if(map[ransomNote[i]]>1)
                map[ransomNote[i]]-=1;
                else
                    map.erase(ransomNote[i]);
            }else{
                return false;
            }
        }
        return check;
    }
};
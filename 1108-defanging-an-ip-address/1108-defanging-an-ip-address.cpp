class Solution {
public:
    string defangIPaddr(string ad) {
        string temp="";
        for(int i=0;i<ad.size();i++){
            if(ad[i]=='.'){
                temp+="[.]";
            }else
                temp+=ad[i];
        }return temp;
    }
};
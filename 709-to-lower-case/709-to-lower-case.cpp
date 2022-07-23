class Solution {
public:
    string toLowerCase(string s) {
        for(auto &it:s){
            if(it>='A' and it<='Z'){
                it=it+32;
            }
        }return s;
    }
};
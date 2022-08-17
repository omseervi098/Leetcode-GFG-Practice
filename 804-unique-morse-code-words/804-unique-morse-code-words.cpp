class Solution {
public:
    vector<string> v={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> s1;
        for(auto it:words){
            string s="";
            for(auto i:it){
                s+=v[i-'a'];
            }
            s1.insert(s);
        }
        return s1.size();
    }
};
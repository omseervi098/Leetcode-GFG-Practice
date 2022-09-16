class Solution {
public:
    vector<string> str={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
     vector<string> helper(string digits) {
        if(digits.size()==0)
            return {""};
        int temp=digits[0]-'0';
        vector<string> small=helper(digits.substr(1));
        vector<string>output(small.size()*str[temp].size());int k=0;
        for(int i=0;i<small.size();i++){
            for(int j=0;j<str[temp].size();j++){
                string te=str[temp][j]+small[i];
                output[k++]=te;
            }
        }
       return output;
    }
     vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
            return {};
         return helper(digits);
    }
   
};
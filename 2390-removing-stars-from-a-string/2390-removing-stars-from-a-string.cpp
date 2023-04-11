class Solution {
public:
    string removeStars(string s) {
        int cnt=0;
        string temp="";
        stack<char> stt;
        for(int i=0;i<s.size();i++){
            if(s[i]!='*'){
                stt.push(s[i]);
            }else{
                stt.pop();
            }
        }
        while(!stt.empty()){
            temp+=stt.top();
            stt.pop();
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};
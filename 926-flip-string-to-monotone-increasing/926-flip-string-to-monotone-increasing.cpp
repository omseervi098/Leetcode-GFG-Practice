class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int cnt1=0,flip=0;
        for(int i=0;i<s.size();i++){
            //cout<<cnt1<<" "<<flip<<endl;
            if(s[i]=='0'){
                flip++;
                flip=min(cnt1,flip);
            }else{
                cnt1++;
            }
        }
        return flip;
    }
};
class Solution {
public:
    int minDeletionSize(vector<string>& s) {
        int cnt=0;
        for(int i=0;i<s[0].size();i++){
            string temp="";
            for(int j=0;j<s.size();j++){
                temp+=s[j][i];
            }
            string t1=temp;
            
            sort(temp.begin(),temp.end());
            if(temp!=t1){
                cnt++;
            }
        }return cnt;
    }
};
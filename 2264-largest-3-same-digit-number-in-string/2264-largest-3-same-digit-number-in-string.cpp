class Solution {
public:
    string largestGoodInteger(string num) {
        int mx=0;string ans="";
        for(int i=0;i<num.size()-2;i++){
            if(num[i]==num[i+1] and num[i+1]==num[i+2]){
                string temp=num.substr(i,3);
                int n=stoi(temp);
                if(n>=mx){
                    mx=n;
                    ans=temp;
                }
            }
        }
        return ans;
    }
};
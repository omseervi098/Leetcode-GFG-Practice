class Solution {
public:
    string helper(int n,int st){
        if(n==1)
            return "1";
        string sans=helper(n-1,st);
        string temp="";
        int j=0;
        if(sans.size()==1){
            temp+="1";
            temp+=sans[0];
            return temp;
        }
        for(int i=1;i<=sans.size();i++){
            if(sans[i]!=sans[j]){
                temp+="1";
                temp+=sans[j++];
                continue;
            }
            while(sans[i]==sans[j] and  i<sans.size()){
                i++;
            }
            temp+=(i-j)+'0';
            temp+=sans[j];
            j=i;
        }
        return temp;
    }
    string countAndSay(int n) {
        return helper(n,n);
    }
};
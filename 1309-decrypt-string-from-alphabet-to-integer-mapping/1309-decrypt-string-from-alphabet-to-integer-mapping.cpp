class Solution {
public:
    string freqAlphabets(string s) {
        string str="";
        unordered_map<char,string> m;
        int j=0,n=s.size()-1;
        for(int i=n;i>=0;i--){
            if(s[i]=='#'){
                int temp=stoi(s.substr(i-2,2));
                cout<<temp<<endl;
                str+=temp+'a'-1;
                i-=2;
            }else{
                str+=(s[i]-'0')+'a'-1;
                cout<<str<<endl;
            }
        }
        reverse(str.begin(),str.end());
        return str;
    }
};
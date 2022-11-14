class Solution {
public:
    string reverseWords(string s) {
        int i=0;
        while(i<s.size() and s[i]==' ') i++;
        int l=i;
        i=s.size()-1;
        while(i>=0 and s[i]==' ')i--;
        int h=i,temp=h;
        int j=l;
        for(int i=l;i<=h;i++){
            if(s[i]==' '){
                s[j++]=' ';
                int t1=temp;
               while(i<=h and s[i]==' '){i++;temp--;}i--;
               if(t1!=temp) temp++;
            }else{
                s[j++]=s[i];
            }
        }
        h=temp;
        reverse(s.begin()+l,s.begin()+h+1);
        cout<<s<<" "<<l<<" "<<temp<<endl;
        j=l;
        for(i=l;i<=h+1;i++){
            if(s[i]==' '||i==h+1){
                int st=j,end=i-1;
                while(st<end){
                    swap(s[st++],s[end--]);
                }
                j=i+1;
            }
        }
        return s.substr(l,h-l+1);
    }
};
#define ll long long
class help{
    public:
    ll val;
    ll mul;
    ll left;
    ll right;
    ll temp;
    string str;
    help(ll val,ll mul,ll left,ll right,ll temp,string str){
        this->val=val;
        this->mul=mul;
        this->left=left;
        this->right=right;
        this->temp=temp;
        this->str=str;
    }
};
class Solution {
public:
    string decodeAtIndex(string s, int k) {
        stack<help> st;
        string word="";
        ll sz=0;
        bool flag=false;
        for(int i=0;i<s.size();i++){
            if(s[i]>='0' and s[i]<='9'){
                if(!flag){
                    st.push(help(sz,s[i]-'0',0,0,sz*1ll*(s[i]-'0'),word));
                    flag=true;
                }
                else{
                    help t=st.top();
                    st.push(help(sz,s[i]-'0',0,0,0,word));
                    st.push(help(t.val*1ll*t.mul+sz,s[i]-'0',t.val*1ll*t.mul,sz,(t.val*1ll*t.mul+sz)*1ll*(s[i]-'0'),""));
                } 
                word="";
                sz=0;
            }else{
                word+=s[i];
                sz++;
            }
        }
        // while(st.size()){
        //     help t=st.top();
        //     cout<<t.val<<" "<<t.mul<<" "<<t.left<<" "<<t.right<<" "<<t.temp<<" "<<t.str<<endl;
        //     st.pop();
        // }
        
        while(st.size()){
            help t=st.top();st.pop();
            ll mod=k%t.val;
            if(mod==0) mod=t.val;
            while(mod<=t.left){
                while(st.size()>1 and mod>st.top().temp) st.pop();
                t=st.top();st.pop();
                mod=mod%t.val;
                if(mod==0) mod=t.val;
            }
            if(t.left==0 and t.right==0) {
                string stri="";
                stri+=t.str[mod-1];
                return stri;
            }
            if(mod>t.left){
                mod-=t.left;
                help z=st.top();st.pop();
                string stri="";
                stri+=z.str[mod-1];
                return stri;
            }
        }
        string temp="";
        temp+=s[k-1];
        return temp;
        
    }
};
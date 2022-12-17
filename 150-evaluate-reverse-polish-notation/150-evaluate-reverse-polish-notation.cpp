
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> s;
        for(auto i:tokens){
            if(s.empty()){
                s.push(stoi(i));
            }else{
                if(i=="+"||i=="-"||i=="*"||i=="/"){
                    long long a=s.top(),b=0;
                    s.pop();
                    b=s.top();
                    s.pop();
                    //cout<<a<<" "<<b<<endl;
                    if(i=="+"){
                        s.push(a+b);
                    }else if(i=="-"){
                        s.push(b-a);
                    }else if(i=="*")
                        s.push(a*b);
                    else
                        s.push(b/a);
                }else{
                    s.push(stoi(i));
                }
            }
        }
        return s.top();
    }
};
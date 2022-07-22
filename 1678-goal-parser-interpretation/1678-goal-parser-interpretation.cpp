class Solution {
public:
    string interpret(string command) {
        unordered_map<string,string> m;
        m["()"]='o';
        m["(al)"]="al";
        m["G"]='G';
        string str="";
        int n=command.size();
        for(int i=0;i<n-1;i++){
           
            if(command[i]=='(' and command[i+1]==')'){
                str+='o';i++;
            }else if(command[i]=='G'){
                str+='G';
            }else if(command[i]=='(' and command[i+1]=='a'){
                str+="al";
                i+=3;
            }
        }
        if(command[n-1]=='G')str+='G';
        return str;
    }
};
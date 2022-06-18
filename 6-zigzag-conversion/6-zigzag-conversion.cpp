class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> v(numRows,vector<char>(s.size(),'0'));
        string str="";
        int k=0,col=0;
        while(k<s.size()){
            int i=0;
            for(i=0;i<numRows and k<s.size();i++){
                v[i][col]=s[k++];
            }
            col++;i-=2;
            int j=col;
            if(k==s.size())break;
            for(;i>=1 and j<(col+numRows-1) and k<s.size();i--,j++){
                v[i][j]=s[k++];
            }
            col=j;
        }
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].size();j++){
                if(v[i][j]!='0')
                    str+=v[i][j];
            }
        }
        return str;
    }
};
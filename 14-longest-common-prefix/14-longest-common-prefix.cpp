class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string temp=strs[0];
        for(int i=1;i<strs.size();i++){
            int k=0,j;
            for(j=0;j<strs[i].size();j++){
                if(strs[i][j]==temp[k]){
                    k++;
                }else {
                    break;
                }   
            }
            temp=temp.substr(0,k);
             cout<<temp<<endl;
        }return temp;
    }
};
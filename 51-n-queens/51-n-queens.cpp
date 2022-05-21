class Solution {
public:
    bool issafe(vector<string>&v,int row,int col){
        //row check
        for(int i=0;i<=row;i++){
            if(v[i][col]=='Q')
                return false;
        }
        for(int i=0;i<=col;i++){
            if(v[row][i]=='Q')
                return false;
        }
         int r = row - 1, c = col - 1;
        while(r >= 0 && c >= 0){
           if(v[r--][c--] == 'Q'){
              return false;
           }
        }
        r = row - 1, c = col + 1;
       while(r >= 0 && c < v.size()){
          if(v[r--][c++] == 'Q'){
              return false;
          }
       }
        return true;
    }
    bool helper(vector<string> &v,vector<vector<string>>&output,int row){
        if(row==v.size()){
            output.push_back(v);
            return true;
        }
        for(int i=0;i<v[row].size();i++){
            if(issafe(v,row,i)){
                v[row][i]='Q';
                bool check=helper(v,output,row+1);
                v[row][i]='.';
            }
        }
       return false;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> help;
        vector<string> ans(n,string(n,'.'));
        bool check=helper(ans,help,0);
        return help;
    }
};
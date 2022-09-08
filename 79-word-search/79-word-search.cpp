class Solution {
public:
    bool dfs(vector<vector<char>> &board,vector<vector<bool>> &visited,int x,int y,int m,int n,string word){
        if(word.size()==0){        
            return true;
        }
       // cout<<word.size()<<endl;
        if(x<0 || y<0 ||x==m || y==n ){
            return false;
        }
        char c=board[x][y];
        board[x][y]='*';
        bool top=false,left=false,down=false,right=false;
        if(y+1<n and word[0]==board[x][y+1] ){
             right=dfs(board,visited,x,y+1,m,n,word.substr(1));
        }
        if(y-1>=0 and word[0]==board[x][y-1] ){
             left=dfs(board,visited,x,y-1,m,n,word.substr(1));
        }
        if(x+1<m and word[0]==board[x+1][y] ){
             down=dfs(board,visited,x+1,y,m,n,word.substr(1));
        }
        if(x-1>=0 and word[0]==board[x-1][y] ){
             top=dfs(board,visited,x-1,y,m,n,word.substr(1));
        }
        board[x][y]=c;
        return top || down || left || right;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),false));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]==word[0] and !visited[i][j]){
                    string temp=word.substr(1);
                    bool check=dfs(board,visited,i,j,board.size(),board[i].size(),temp);
                    cout<<check<<endl;
                    if(check)
                        return true;
                }
            }
        }
        return false;
    }
};
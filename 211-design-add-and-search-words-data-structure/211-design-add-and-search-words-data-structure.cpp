class Trinode {
   public:
    char data;
    Trinode **child;
    bool isterminal;
    int childCount;

    Trinode(char data) {
        this->data = data;
        child= new Trinode *[26];
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
        isterminal = false;
        childCount = 0;
    }
};

class WordDictionary {
    Trinode *root;
public:
    WordDictionary() {
        root = new Trinode('\0');
    }
    void insert(Trinode* node,string word){
        if(!word.size()) {
            node->isterminal=true;
            return;}
        int idx=word[0]-'a';
        Trinode* child;
        if(node->child[idx]!=NULL)
            child=node->child[idx];
        else
        {
            child=new Trinode(word[0]);
            node->child[idx]=child;
        }
        insert(child,word.substr(1));
    }
    void addWord(string word) {
        insert(root,word);
    }
     bool search(Trinode* node,string &word,int j){
         if(node==nullptr) return false;
        if(j==word.size()) return node->isterminal;
         if(word[j]=='.') {
             int i=0;
             for(i=0;i<26;i++){
                 if(search(node->child[i],word,j+1))return true;
             }
             return false;
             
         }else{
            int idx=word[j]-'a';
            return search(node->child[idx],word,j+1);
         }
    }
    bool search(string word) {
        return search(root,word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
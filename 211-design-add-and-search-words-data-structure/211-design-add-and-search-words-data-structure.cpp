class Trinode {
   public:
    Trinode *child[26];
    bool isterminal;

    Trinode() {
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
        isterminal = false;
    }
};

class WordDictionary {
    Trinode *root;
public:
    WordDictionary() {
        root = new Trinode();
    }
    void insert(Trinode* node,string word){
        Trinode *t=node;
        for(auto &it:word){
            if(!t->child[it-'a']){
                t->child[it-'a']=new Trinode();
            }
            t=t->child[it-'a'];
        }
        t->isterminal=true;
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
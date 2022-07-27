class Trinode {
    public:
    Trinode ** child;
    char val;
    bool isterminal;
    Trinode(char val){
        child=new Trinode*[26];
        for(int i=0;i<26;i++)
            child[i]=nullptr;
        isterminal= false;
        this->val=val;
    }
};
class Trie {
    public:
    Trinode* root;
    Trie() {
        root=new Trinode('\0');
    }
    private:
    void insert(Trinode* node,string word){
        if(!word.size()) {
            node->isterminal=true;
            return;
        }
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
    bool search(Trinode* node,string word){
        if(!word.size()) return node->isterminal;
        int idx=word[0]-'a';
        if(node->child[idx])
            return search(node->child[idx],word.substr(1));
        else
            return false;
    }
    bool startsWith(Trinode* node,string word){
        if(!word.size()) return true;
        int idx=word[0]-'a';
        if(node->child[idx])
            return startsWith(node->child[idx],word.substr(1));
        else
            return false;
    }
    public:
    void insert(string word) {
        insert(root,word);
    }
    
    bool search(string word) {
        
        return search(root,word);
    }
    
    bool startsWith(string prefix) {
         return startsWith(root,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
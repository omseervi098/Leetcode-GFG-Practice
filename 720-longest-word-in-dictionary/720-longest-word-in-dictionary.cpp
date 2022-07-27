class TrieNode {
   public:
    TrieNode **children;
    bool isTerminal;

    TrieNode() {
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;
    public:
    int count;
    Trie() {
        this->count = 0;
        root = new TrieNode();
    }
    void insertWord(TrieNode *node, string word) {
        TrieNode* curr=node;
        for(auto it:word){
             if(!curr -> children[it - 'a'])
				  curr -> children[it - 'a'] = new TrieNode();
			 curr = curr -> children[it - 'a'];
        }
        curr->isTerminal=true;
    }
    void insertWord(string word) {
        insertWord(root,word);
    }
    bool search(TrieNode* node,string word){
        if(!word.size()) return node->isTerminal;
        int idx=word[0]-'a';
        if(node->children[idx])
            return search(node->children[idx],word.substr(1));
        else
            return false;
    }
    bool search(string word){
        return search(root,word);
    }


};
class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie t1;
        for(auto it:words){
            t1.insertWord(it);
        }
        int mxlen=0;
        string ans="";
        for(auto it:words){
            int n=it.size(),i=1;
            for(i=1;i<n;i++){
                string s=it.substr(0,i);
                if(!t1.search(s)) {
                    break;
                }
            }
            if(i==n){
                if(n>mxlen)
                {
                    mxlen=n;
                    ans=it;
                }else if(n==mxlen){
                    if(it<ans){
                        ans=it;
                    }
                }
            }
        }
        return ans;
    }
};
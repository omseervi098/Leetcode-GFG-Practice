class TrieNode
    {
        public:
        TrieNode* links[26];
        vector<int>idx;
    };

class Trie {
    TrieNode *root;

   public:
    int count;
    Trie() {
        this->count = 0;
        root = new TrieNode();
    }

    void insert(string s,int id)
        {
            TrieNode* node=root;
            for(auto &ch:s)
            {
                if(!node->links[ch-'a'])
                    node->links[ch-'a']=new TrieNode();
                
                node=node->links[ch-'a'];
                node->idx.push_back(id);
            }
        }
    vector<int> search(string s)
        {
            TrieNode* node=root;
            for(int i=0;i<s.length();i++)
            {
                if(!node->links[s[i]-'a'])return {};
                node=node->links[s[i]-'a'];
            }
            return node->idx;
        }
};
class Solution {
    public:
    Trie t1;
    vector<vector<string>> suggestedProducts(vector<string>& input, string w) {
        vector<vector<string>>v;
        sort(input.begin(),input.end());
        for(int i=0;i<input.size();i++)
        {
            t1.insert(input[i],i);
        }
        string s;
        int len=w.length();
        vector<vector<string>>res(len);
        
        for(int i=0;i<w.length();i++)
        {
            s+=w[i];
            vector<int>t=t1.search(s);
            for(int j=0;j<min(3,(int)t.size());j++)
            {
                res[i].push_back(input[t[j]]);
            }
        }
        
        return res;
    }
};

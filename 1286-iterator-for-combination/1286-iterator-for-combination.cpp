class CombinationIterator {
public:
    vector<string> ans;
    int nxt;
    void combination(string s,int k,string out,vector<string> &v,int st){
        if(k==0) {
            v.push_back(out);
            return;
        }if(st==s.size()) return;
        for(int i=st;i<s.size();i++){
            combination(s,k-1,out+s[i],v,i+1);
        }
    }
    CombinationIterator(string ch, int k) {
        combination(ch,k,"",ans,0);
        nxt=0;
    }
    
    string next() {
        if(!hasNext()) return "";
        return ans[nxt++];
    }
    
    bool hasNext() {
        if(nxt==ans.size()) return false;
        return true;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
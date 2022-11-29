class RandomizedSet {
public:
    unordered_map<int,int> mp;
    vector<int> v;
    int k;
    RandomizedSet() {
        k=0;
    }
    
    bool insert(int val) {
        if(mp.count(val)>0) return false;
        v.push_back(val);
        mp[val]=k;
        k++;
        return true;
    }
    
    bool remove(int val) {
        if(mp.count(val)>0){
            v[mp[val]]=v[k-1];
            v.pop_back();
            mp[v[k-1]]=mp[val];
            k--;
            mp.erase(val);
            return true;
        }return false;

    }
    
    int getRandom() {
        return v[rand()%k];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
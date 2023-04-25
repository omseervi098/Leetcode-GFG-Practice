class SmallestInfiniteSet {
    set<int> s;
    public:
    SmallestInfiniteSet() {
        // for(int i=1;i<=1000;i++) s.insert(i);
    }
    
    int popSmallest() {
        int p=1;
        while(s.count(p)) p++;
        int val=p++;
        s.insert(val);
        return val;
    }
    
    void addBack(int num) {
        if(s.count(num)) s.erase(num);
    }
};

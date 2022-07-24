
class NumberContainers {
public:
    map<int,int> n;
    map<int,set<int>> m;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(n[index])
            m[n[index]].erase(index);
        n[index]=number;
        m[number].insert(index);
    }
    
    int find(int number) {
        if(m.count(number)==0)return -1;
        if(*m[number].begin()==0) return -1;
        return (*m[number].begin());
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
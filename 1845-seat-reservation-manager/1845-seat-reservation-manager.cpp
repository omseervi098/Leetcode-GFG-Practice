class SeatManager {
    public:
    vector<bool> v;
    int sz;
    set<int> s;
    SeatManager(int n):sz(n){
        for(int i=1;i<=n;i++) s.insert(i);
    }
    
    int reserve() {
        int temp=*s.begin();
        s.erase(temp);
        return temp;
    }
    
    void unreserve(int seatNumber) {
        s.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
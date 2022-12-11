class Allocator {
    int n;
    unordered_map<int,vector<int>> mp;
    vector<int> freed;
public:
    Allocator(int n) : n(n){
        freed.resize(n);
    }

    int allocate(int size, int mID) {
        for(int i=0;i<n;i++){
            if(freed[i]==0){
                int k=i,b=0;
                while(i<n and freed[i]==0 and b<size){
                    i++;b++;
                }
                if(b>=size){
                    for(int j=k;j<k+size;j++){
                        freed[j]=mID; 
                        mp[mID].push_back(j);
                    }
                    return k;
                }
            }
        }
        return -1;
    }

    int free(int mID) {
        vector<int> idx=mp[mID];
        for(auto &i:idx){
            freed[i]=0;
        }
        mp.erase(mID);
        return idx.size();
    }
};

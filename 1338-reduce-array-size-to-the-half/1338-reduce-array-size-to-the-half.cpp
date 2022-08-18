struct comp {
    template <typename T>
  
    // Comparator function
    bool operator()(const T& l,
                    const T& r) const
    {
        if (l.second != r.second) {
            return l.second > r.second;
        }
        return l.first < r.first;
    }
};

class Solution {
public:
   
    int minSetSize(vector<int>& arr) {
        
        map<int,int> m;
        set<int> s;
        for(auto it:arr){
            m[it]+=1;
        }
        set<pair<int, int>, comp> S(m.begin(),
                                   m.end());

        int n=0;
        int half=(arr.size()+1)/2.0;
        int ans=0;
        cout<<half<<endl;
        for(auto it:S){
                cout<<n<<endl;
                if(n>=half) break;
                n+=it.second; ans++;
                
               
        }
        return ans;
    }
    
};
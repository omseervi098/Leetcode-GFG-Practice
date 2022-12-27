class Solution {
public:
    int maximumBags(vector<int>& c, vector<int>& r, int x) {
        vector<int> v;
        int cnt=0;
        for(int i=0;i<r.size();i++){
            int sum=c[i]-r[i];
            if(sum>0){
                v.push_back(sum);
            }
            if(sum==0) cnt++;
        }
        sort(v.begin(),v.end());
        
        for(auto i:v){
            if(x>=i){
                x-=i;
                cnt++;
            }
        }
        return cnt;
    }
};
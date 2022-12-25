class Solution{
public:

    vector<int> answerQueries(vector<int>& n, vector<int>& q) {
        vector<int> v;
        sort(n.begin(),n.end());
        for(auto i:q){
            int sum=0;
            int cnt=0;
            for(int j=0;j<n.size();j++){
                sum+=n[j];
                if(sum>i){
                    sum-=n[j];
                    break;
                }cnt++;
            }
            v.push_back(cnt);
        }return v;
    }
};
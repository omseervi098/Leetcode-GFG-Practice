class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> st,end,ans;
        for(auto i:flowers){
            st.push_back(i[0]);
            end.push_back(i[1]);
        }
        sort(st.begin(),st.end());
        sort(end.begin(),end.end());
        // 1 3 4 9
        // 6 7 12 13
        //
        for(auto i:people){
            int u=lower_bound(end.begin(),end.end(),i)-end.begin();
            int l=upper_bound(st.begin(),st.end(),i)-st.begin();
            cout<<u<<" "<<l<<endl;
            ans.push_back(l-u);
        }
        return ans;
    }
};
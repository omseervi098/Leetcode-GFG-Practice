class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size()&1) return {};
        unordered_map<int,pair<int,int>>m;
        //1 2 2 2 4 4
        //1 - 2 
        vector<int> ans;
        sort(changed.begin(),changed.end());
        for(auto it:changed){
            if(m.count(it)>0){
                ans.push_back(m[it].first);
                m[it].second-=1;
                if(m[it].second==0)
                m.erase(it);
                continue;
            }else{
                if(m.count(2*it)==0)
                m[2*it]={it,1};
                else
                   m[2*it].second+=1;
            }
        }
        if(ans.size()==changed.size()/2)
            return ans;
        return {};
    }
};
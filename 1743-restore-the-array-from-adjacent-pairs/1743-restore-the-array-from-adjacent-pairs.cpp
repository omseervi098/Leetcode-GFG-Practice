class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& ap) {
        unordered_map<int,vector<int>> mp;
        for(auto i:ap){
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
        }
        int temp1=0,n=ap.size()+1;
        for(auto i:mp){
            if(i.second.size()==1){
                temp1=i.first;
                break;
            }
        }
        vector<int> v;
        set<int> visited;
        v.push_back(temp1);
        visited.insert(temp1);
        int temp=mp[temp1][0];
        v.push_back(temp);
        visited.insert(temp);
        while(mp[temp].size()==2){
            if(visited.count(mp[temp][0])==0){
                temp=mp[temp][0];
                v.push_back(temp);
                visited.insert(temp);
            }
            else{
                temp=mp[temp][1];
                v.push_back(temp);
                visited.insert(temp);
            }
        }
        return v;
    }
};
bool sortByVal(const pair<char, int> &a,const pair<char, int> &b) 
{ 
    return (a.second > b.second); 
} 
class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mp;
        for(auto it:s) mp[it]+=1;
        vector<pair<char, int>> vec;
        for (auto it:mp) 
        {
            vec.push_back(make_pair(it.first, it.second));
        }
        sort(vec.begin(), vec.end(), sortByVal); 
        string ans="";
        for(auto it:vec){
            int k=it.second;
            while(k-->0){
                ans+=it.first;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int missingNumber(vector<int>& a) {
        int mn=*min_element(a.begin(), a.end());
        int mx=*max_element(a.begin(), a.end());
        unordered_map<int,bool> map;
        for(int i=0;i<a.size();i++)
            map[a[i]]=1;
        mn=mn!=0?mn-1:mn;
        int no=-1;
        for(int i=mn;i<=mx;i++){ 
          
            if(map.count(i)<=0){
                no=i;
                break;
            }
        }
        if(no==-1)no=mx+1;
        return no;
    }
};
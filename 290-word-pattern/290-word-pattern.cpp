
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> map;
        unordered_map<string,bool> map1;
        vector<string> result;
        int st=0;
        cout<<s.size()<<endl;
        for(int i=0;i<=s.size();i++){
             if(s[i]==' ' || i==s.size()){
                 int end=i-1;
                 string temp="";
                 for(int j=st;j<=end;j++){
                     temp+=s[j];
                 }
                 result.push_back(temp);
                 st=i+1;
            }
        }
        for(auto it:result){
            cout<<it<<" ";
        }cout<<endl;
        if(result.size()!=pattern.size()) return false;
        for(int i=0;i<pattern.size();i++){
            
            if(map.count(pattern[i])>0){
                if(result[i]!=map[pattern[i]]){
                    return false;
                }
                
            }else
            {
                if(map1.count(result[i])>0) return false;
                map[pattern[i]]=result[i];
                map1[result[i]]=true;
            }
            //cout<<pattern[i]<<" "<<map[pattern[i]]<<" "<<result[i]<<endl;
        }
        return true;
    }
};
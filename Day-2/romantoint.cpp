//Problem no 13
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> val;
        val['I']=1;
        val['V']=5;
        val['X']=10;
        val['L']=50;
        val['C']=100;
        val['D']=500;
        val['M']=1000;
        int ans=0;
        for(int i=0;i<s.size();i++){
            int current=val[s[i]];
            int next=0;
            next=val[s[i+1]];
            if(current>=next){
                ans+=current;
            }if(current<next){
                ans+=next-current;
                i++;
            }
        }
        return ans;
    }
};
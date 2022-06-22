class Solution {
public:
    int longestPalindrome(string s) {
        int mx=INT_MIN;
        unordered_map<char,int> map;
        for(auto it:s){
            map[it]+=1;
        }
        int sum=0;
        bool check=false;
        for(auto it:s){
            if(map[it]>=2){
                sum+=2;
                map[it]-=2;
            }else if(map[it]==1){
                check=true;
            }
        }
        if(check)return sum+1;
        return sum;
    }
};
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        if(s1==s2)return true;
        int swapfirst=-1;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                if(swapfirst==-1){
                    swapfirst=i;
                }
                else{
                    swap(s1[i],s1[swapfirst]);
                    return s1==s2;
                }
            }
        }return s1==s2;
    }
};
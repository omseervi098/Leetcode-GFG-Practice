class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        if(s1==s2)return true;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                swap(s1[i],s1[j]);
                if(s1==s2)return true;
                else
                    swap(s1[i],s1[j]);
            }
        }return false;
    }
};
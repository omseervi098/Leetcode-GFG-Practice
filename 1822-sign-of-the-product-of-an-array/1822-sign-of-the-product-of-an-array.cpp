class Solution {
public:
    int arraySign(vector<int>& nums) {
        int cntofneg=0;
        bool check=false;
        for(auto it:nums){
            if(it<0)cntofneg++;
            else if(it==0)check=true;
        }if(cntofneg%2==0 and !check) return 1;
        else if(cntofneg%2==1 and !check)return -1;
        return 0;
    }
};
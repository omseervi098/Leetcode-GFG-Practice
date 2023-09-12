class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // int cnt=0;
        // for(int i=0;i<nums.size();i++){
        //     int sm=0;
        //     for(int j=i+1;j<nums.size();j++){
        //         sm+=nums[j];
        //         if(sm==k) cnt++;
        //     }
        // }
        //using map
        unordered_map<int,int> m;
        int sm=0,cnt=0;
        m[0]=1;
        for(int i=0;i<nums.size();i++){
            sm+=nums[i];
            if(m.count(sm-k)>0){
                cnt+=m[sm-k];
            }
            m[sm]++;
        }
        return cnt;
    }
};
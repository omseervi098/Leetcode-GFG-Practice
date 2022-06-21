class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // int cnt=0;
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i+1;j<=nums.size();j++){
        //         int sum=0;
        //         for(int k=i;k<j;k++){
        //             sum+=nums[k];
        //         }
        //         if(sum==k)
        //             cnt++;
        //     }
        // }return cnt;
        
//         vector<int> presum(nums.size()+1,0);
//         int cnt=0;
        
//         presum[0]=0;
//         for(int i=0;i<nums.size();i++){
//             presum[i+1]=presum[i]+nums[i];
//         }
//         for(int i=0;i<nums.size();i++){
//             for(int j=i+1;j<=nums.size();j++){
//                 if(presum[j]-presum[i]==k)
//                     cnt++;
//             }
//         }
//         return cnt;
        
        //hashmap
        unordered_map<int,int> map;
        map[0]=1;
        int sum=0,cnt=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(map.count(sum-k)>0){
                cnt+=map[sum-k];
            }
            map[sum]++;
        }return cnt;
    }
};
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> map;
        for(auto it:nums)
            map[it]+=1;
        for(auto it:nums)
        {
            if(map[it]>(nums.size()/2))
               return it;
        }
        return 0;
    }
};
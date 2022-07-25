class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> ourmap;
        for(int i=0;i<nums.size();i++)
        {
            ourmap[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(ourmap.at(nums[i])>=2)
            {
                return true;
            }
        }
        return false;
    }
};
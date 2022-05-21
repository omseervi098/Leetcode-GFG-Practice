class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int> map; //used to check for valid pair
        vector<int> result;//used to store the result and used to return it
        for (int i = 0 ; i < nums.size() ; i++){
            if (map.find(target - nums[i]) != map.end()){ //found case
                result.push_back(map[target - nums[i]]); //get the index 
                result.push_back(i); //get current index
                return result;
            }
            map[nums[i]] = i; //store into the hash_table , key will be the actual number , value is the indices
        }
        return result;
    }
};
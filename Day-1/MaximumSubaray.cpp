//Problem no 53
// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.

// BRUTE (TLE) SOLUTION O(n^3) time and O(1) space
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxVal = INT_MIN;
        int const n = nums.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int curSum = 0;
                for (int k = i; k <= j; k++) {
                    curSum += nums[k];
                }
                maxVal = max(maxVal, curSum);
            }
        }
        
        return maxVal;
    }
};
// BETTER SOLUTION
// TIME  O(N^2)
// SPACE O(1)

class Solution {
public:    
    int maxSubArray(vector<int>& nums) {
        int maxVal = INT_MIN;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int curVal = 0;
            for (int j = i; j < n; j++) {
                curVal += nums[j];
                if (curVal > maxVal)
                    maxVal = curVal;
                if (curVal < 0)
                    break;
            }
        }    
        
        return maxVal;
    }
};
//Kedans algorithm O(N) TIME AND O(1) SPACE
class Solution {
public:
    
    int maxSubArray(vector<int>& nums) {
        int sum=0,ans=nums[0];
        for(int i=0;i<nums.size();i++){
            if(sum<0)
                sum=0;
            sum+=nums[i];
            ans=max(sum,ans);
        }
        return ans;
    }
};
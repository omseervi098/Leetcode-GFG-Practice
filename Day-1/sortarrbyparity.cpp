//In this problem we need to sort the array by parity i.e. all even should come first and all odd should come later
//1st approach same time but taking more o(n) space
vector<int> sortArrayByParity(vector<int>& nums) {
    vector<int> arr;
    for(int i=0;i<nums.size();i++){
        if(nums[i]%2==0){
            arr.push_back(nums[i]);
        }
    }
    for(int i=0;i<nums.size();i++){
        if((nums[i]%2)==1){
            arr.push_back(nums[i]);
        }
    }
    return arr;
}
//second approach same time but in O(1) space
vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=n-1;
        while(i<j)
        {
            if(nums[i]%2==1 && nums[j]%2==0)
            {
                swap(nums[i],nums[j]);
                i++;j--;
            }
            else if(nums[i]%2==0)
                i++;
            else
                j--;
        }
        return nums;
    }
};

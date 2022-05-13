// Problem no 108
//u can do more better than this using bfs by queue
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>&nums,int st,int end){
        if(st>end)return NULL;
        int mid=(st+end)/2.0;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=sortedArrayToBST(nums,st,mid-1);
        root->right=sortedArrayToBST(nums,mid+1,end);
        return root;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums,0,nums.size()-1);
    }
};
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# class Solution {
# public:
#     int helper(TreeNode* root,bool left,int d){
#         if(root==NULL) return d;
#         if(left) return max(helper(root->right,false,d+1),helper(root->left,true,0));
#         return max(helper(root->left,true,d+1),helper(root->right,false,0));
#     }
#     int longestZigZag(TreeNode* root) {
#         return max(helper(root->left,true,0),helper(root->right,false,0));
#     }
# };
class Solution:
    def longestZigZag(self, root: Optional[TreeNode]) -> int:
        def helper(root:Optional[TreeNode],left,d) -> int:
            if root==None:
                return d
            if left:
                return max(helper(root.right,False,d+1),helper(root.left,True,0))
            return max(helper(root.left,True,d+1),helper(root.right,False,0))
        return max(helper(root.left,True,0),helper(root.right,False,0))
        
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool ans=false;
    vector<int> m,n;
    void helper(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL and root2==NULL){
            return;
        }
        if(root1==NULL){
            helper(root1,root2->left);
            if(root2->left==NULL and root2->right==NULL)  n.push_back(root2->val);
            helper(root1,root2->right);
        }
        else if(root2==NULL){
            helper(root1->left,root2);
            if(root1->left==NULL and root1->right==NULL)  m.push_back(root1->val);
            helper(root1->right,root2);
        }else{
            helper(root1->left,root2->left);
            if(root1->left==NULL and root1->right==NULL)  m.push_back(root1->val);
            if(root2->left==NULL and root2->right==NULL)  n.push_back(root2->val);
            helper(root1->right,root2->right);
        }
    }
    public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        helper(root1,root2);
        for(auto i:m) cout<<i<<" ";
        cout<<endl;
        for(auto i:n) cout<<i<<" ";
        return m==n;
    }
};
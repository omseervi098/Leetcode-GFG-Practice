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
public:
    void helper(TreeNode* root,int k,vector<int> &v){
        if(root==nullptr)
            return;
        if(v.size()==k) return;
        helper(root->left,k,v);
        if(v.size()==k) return;
        v.push_back(root->val);
        helper(root->right,k,v);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
         helper(root,k,v);
        for(auto it:v)
            cout<<it<<" ";
        cout<<endl;
        return v[v.size()-1];
    }
};
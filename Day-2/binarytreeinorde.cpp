//problem no 94

//recursive dfs
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root!=NULL)
        {
            vector<int> left=inorderTraversal(root->left);
            left.push_back(root->val);
            vector<int>right=inorderTraversal(root->right);
            for(int i=0;i<right.size();i++)
            left.push_back(right[i]);
            return left;
        }vector<int>v;
        return v;
    }
};
//iterative dfs using stack
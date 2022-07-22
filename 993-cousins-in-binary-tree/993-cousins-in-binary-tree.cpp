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
class Solution
{
public:
    bool isCousins(TreeNode *root, int x, int y)
    {

        if (root == NULL)
            return false;
        queue<TreeNode *> q;
        q.push(root);
        q.push(nullptr);
        bool a=false,b=false;
        while (!q.empty())
        {
            TreeNode*front = q.front();
            q.pop();
            if(front==nullptr){
                if(a and b)return true;
                a=0;b=0;
                if(q.empty())
                    break;
                q.push(nullptr);
                continue;
            }
            if(front->val==x)
                a=1;
            else if(front->val==y)
                b=1;
            if(front->left!=nullptr and front->right!=nullptr){
                if(front->left->val==x and front->right->val==y)
                    return false;
                else if(front->left->val==y and front->right->val==x)
                    return false;
            }
            if (front->left != NULL)
                q.push(front->left);
            if (front->right != NULL)
                q.push(front->right);
        }
        return false;
    }
};
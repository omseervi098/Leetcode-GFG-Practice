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
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr) return {};
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<int> v;
        vector<int> ans;
        while(!q.empty()){
            TreeNode* front=q.front();
            q.pop();
            if(!front){
                ans.push_back(v[v.size()-1]);
                
                v.clear();
                if(q.empty()){
                    break;
                }  
                q.push(NULL);
                continue;
            }else{
                v.push_back(front->val);
            }
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);
        }
        return ans;
    }
};
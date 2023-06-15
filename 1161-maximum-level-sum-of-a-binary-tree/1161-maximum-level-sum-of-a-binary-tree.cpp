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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int sm=0,mx=INT_MIN,mxidx=-1,i=1;
        while(q.size()){
            int n=q.size();
            sm=0;
            for(int i=0;i<n;i++){
                TreeNode* front=q.front();q.pop();
                sm+=front->val;
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            } 
            if(sm>mx){
                mx=sm;
                mxidx=i;
            }
            i++;
        }
        return mxidx;
    }
};
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
//  */
// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) {
//         if(root==nullptr) return {};
//         queue<TreeNode*>q;
//         q.push(root);
//         vector<int> ans;
//         while(!q.empty()){
//             int n=q.size();
//             for(int i=0;i<n;i++){
//                 TreeNode* front=q.front();
//             q.pop();
//                 if(i==n-1)
//                     ans.push_back(front->val);
//             if(front->left)
//                 q.push(front->left);
//             if(front->right)
//                 q.push(front->right);
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> view;
        int idx=0;
        rightView(root, view, 0,idx);
        return view;
    }
private:
    void rightView(TreeNode* root, vector<int>& view, int level,int &idx) {
        if (!root) {
            return;
        }
        cout<<idx<<endl;
        if (idx == level) {
            view.push_back(root -> val);
            idx++;
        }
        
        rightView(root -> right, view, level + 1,idx);
        rightView(root -> left, view, level + 1,idx);
    }
};
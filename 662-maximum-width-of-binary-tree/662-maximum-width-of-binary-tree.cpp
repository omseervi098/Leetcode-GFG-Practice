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
#define ull unsigned long long
class Solution {
public:
    
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,ull>> q;
        vector<ull> v;
        q.push({root,0});
        int mx=0;
        while(q.size()){
            int n=q.size();
            int left=-1,right=-1;
            for(int i=0;i<n;i++){
                auto [front,idx]=q.front();q.pop();
                if(left==-1) left=idx;right=idx;
                if(front->left) q.push({front->left,2*idx+1});
                if(front->right) q.push({front->right,2*idx+2});
            }
            mx=max(mx,right-left+1);
        }
        return mx;
        
    }
};
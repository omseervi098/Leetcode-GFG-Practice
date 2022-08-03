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
class avg{
    public:
    int no;
    int ans;
    int sum;
};
class Solution {
public:
    avg helper(TreeNode* root){
        avg a1;
        if(root==NULL){
            a1.no=0;
            a1.ans=0;
            a1.sum=0;
            return a1;
        }
        avg left=helper(root->left);
        avg right=helper(root->right);
        a1.no=1+left.no+right.no; //6
        a1.sum=root->val+left.sum+right.sum; //24
        int avg=(a1.sum)/(double)(a1.no);
        a1.ans=left.ans+right.ans;
        if(avg==root->val)
            a1.ans+=1;
        //cout<<a1.no<<" "<<a1.sum<<" "<<avg<<" "<<root->val<<" "<<a1.ans<<endl;
        return a1;
    }
    int averageOfSubtree(TreeNode* root) {
        return helper(root).ans;
    }
};
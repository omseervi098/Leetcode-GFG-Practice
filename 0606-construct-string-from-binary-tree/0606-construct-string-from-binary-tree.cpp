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
    string tree2str(TreeNode* root,bool flag=false) {
        if(root==NULL)  return "";
         string temp;
        if(flag) temp='(';
        temp+=to_string(root->val);
        string left=tree2str(root->left,true);
        string right=tree2str(root->right,true);
        if(right!="" and left=="") 
            temp+="()";
        else
            temp+=left;
        temp+=right;
        if(flag) temp+=')';
        return temp;
    }
};
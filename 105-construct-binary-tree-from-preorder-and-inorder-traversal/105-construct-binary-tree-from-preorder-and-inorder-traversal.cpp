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
    TreeNode* buildTree(vector<int>& pre, int pres,int pree,vector<int>& in,int ins,int ine) {
        if(pres>pree ||ins>ine)
            return NULL;
        int prels,prele,prers,prere,inls,inle,inrs,inre;
        int i=pres;
        for(i=ins;i<ine;i++){
            if(in[i]==pre[pres])
                break;
        }
        inls=ins;
        inle=i-1;
        inrs=i+1;
        inre=ine;
        prels=pres+1;
        prele=(inle-inls)+prels;
        prers=prele+1;
        prere=pree;
        TreeNode* root=new TreeNode(pre[pres]);
        root->left=buildTree(pre,prels,prele,in,inls,inle);
        root->right=buildTree(pre,prers,prere,in,inrs,inre);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
};
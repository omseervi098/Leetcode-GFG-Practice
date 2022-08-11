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
class BSTPair{
public:
bool isBST;
long _min;
long _max;
};

class Solution {
public:
long min(long a , long b){
if(a>b){
return b;
}
return a;
}

long max(long a , long b){
    if(a>b){
        return a;
    }
    return b;
}

BSTPair isBst(TreeNode* root){
    //base case
    
    if(root == NULL){
        BSTPair bp;
        bp.isBST = true;
        bp._min = LONG_MAX;
        bp._max = LONG_MIN;
        return bp;
    }
    
    BSTPair leftCall = isBst(root->left);
    BSTPair rightCall = isBst(root->right);
    
    BSTPair myPair;
    
    myPair.isBST = (leftCall.isBST and rightCall.isBST 
        and (root->val > leftCall._max and root->val < rightCall._min));
    
    myPair._min = min(root->val , min(leftCall._min,rightCall._min ));
    myPair._max = max(root->val , max(leftCall._max,rightCall._max ));
        
        
    return myPair;
    
}

bool isValidBST(TreeNode* root) {
    //if it is single node
    if(root->left == NULL and root->right == NULL){
        return true;
    }
    BSTPair bp = isBst(root);
    return bp.isBST;
}
};
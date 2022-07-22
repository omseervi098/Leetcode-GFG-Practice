
class Solution {
public:
    int depthofgivennode(TreeNode* root,int val){
    if(root==NULL)
        return -1;
    if(root->val==val)
    return 0;
    int d1=depthofgivennode(root->left,val);
    if(d1!=-1)
        return d1+1;
    else{
        int d2=depthofgivennode(root->right,val);
        if(d2!=-1)
            return d2+1;
        else
            return -1;
    }
}
bool isnotsibling(TreeNode* root,int p,int q){
    if(root==nullptr||(root->left==nullptr and root->right==nullptr))
        return true;
    if(root->left==nullptr){
        return isnotsibling(root->right,p,q);
    }else if(root->right==nullptr)
        return isnotsibling(root->left,p,q);
    else{
        if(root->left->val==p and root->right->val==q)
          return false;
        else if(root->left->val==q and root->right->val==p)
          return false;
        return isnotsibling(root->left,p,q) and isnotsibling(root->right,p,q);
    }
}
    bool isCousins(TreeNode* root, int x, int y) {
         if(root==nullptr)
        return false;
        
    return (depthofgivennode(root,x)==depthofgivennode(root,y) and isnotsibling(root,x,y));
    }
};
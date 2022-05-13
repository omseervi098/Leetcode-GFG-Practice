//problem no 100
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL and q==NULL)return true;
        else if(p==NULL)
            return false;
        else if(q==NULL)return false;
        if(p->val!=q->val)return false;
        bool left=isSameTree(p->left,q->left);
        bool right=isSameTree(p->right,q->right);
        return left&&right&&p->val==q->val;
    }
};
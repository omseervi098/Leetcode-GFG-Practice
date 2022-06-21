//GFG POTD
// link to problem : https://practice.geeksforgeeks.org/problems/largest-bst/
// Time Complexity: O(N) (N is no of nodes)
// Space Complexity: O(height of BST)
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    class isBST{
        public:
        int max;
        int min;
        bool isbst;
        int size;
    };
    isBST helper(Node* root){
        if(root==NULL){
            isBST b1;
            b1.max=INT_MIN;
            b1.min=INT_MAX;
            b1.isbst=true;
            b1.size=0;
            return b1;
        }
        isBST left=helper(root->left);
        isBST right=helper(root->right);
        isBST ans;
        ans.max=max(root->data,max(left.max,right.max));
        ans.min=min(root->data,min(left.min,right.min));
        ans.isbst=left.isbst and right.isbst and root->data >left.max and root->data<right.min;
        if(ans.isbst) ans.size=1+left.size+right.size;
        else  ans.size=max(left.size,right.size);
        return ans;
    }
    int largestBst(Node *root)
    {
    	return helper(root).size;
    }
};

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
    vector<double> averageOfLevels(TreeNode* root) {
         if(root==NULL)
            return {};
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<double> cpy;
        int noofnodes=0;
        double sum=0;
        while(!q.empty()){
            TreeNode* front=q.front();
            q.pop();
            if(front==NULL){
                if(q.empty()){
                    sum=sum/noofnodes;
                     cpy.push_back(sum);
                    break;
                }
                sum=sum/noofnodes;
                cout<<noofnodes<<" "<<sum<<endl;
                noofnodes=0;
                cpy.push_back(sum);sum=0;
                q.push(NULL);
                continue;
            }
            sum+=front->val;
            noofnodes++;
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);
            
        }
        return cpy;
    }
};
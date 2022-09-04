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
    map<int,map<int,map<int,int>>> map;
    public:
    void dfs(TreeNode* root,int col,int row){
        if(!root) return;
        map[col][row][root->val]+=1;
        dfs(root->left,col-1,row+1);
        dfs(root->right,col+1,row+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root,0,0);
        vector<vector<int>> v;
        for(auto it:map){
            vector<int> temp;
            for(auto i:it.second){
                for(auto s:i.second){
                    int k=s.second;
                    while(k-->0){
                        temp.push_back(s.first);
                    }
                }   
            }
            v.push_back(temp);
        }
        return v;
    }
};
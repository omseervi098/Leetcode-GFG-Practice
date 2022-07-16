/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL)return {};
        vector<vector<int>> v;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> ans;
            int n=q.size();
            for(int i=0;i<n;i++){
                Node* front=q.front();q.pop();
                ans.push_back(front->val);
                for(auto i:front->children){
                    q.push(i);
                }
                
            }v.push_back(ans);
        }
        return v;
    }
};
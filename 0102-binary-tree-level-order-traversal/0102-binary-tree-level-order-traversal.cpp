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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) {
            return res;
        }
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            vector<int> inter;
            for(int i = 0; i < size; i++) {
                TreeNode *t = q.front();
                q.pop();
                if(t->left != NULL) {
                    q.push(t->left);
                }
                if(t->right != NULL) {
                    q.push(t->right);
                }
                inter.push_back(t->val);
            }
            res.push_back(inter);
        }
        return res;
    }
};
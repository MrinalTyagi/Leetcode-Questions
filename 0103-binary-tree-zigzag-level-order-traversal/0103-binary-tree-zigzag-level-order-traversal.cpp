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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) {
            return res;
        }
        queue<TreeNode *> q;
        stack<TreeNode *> s;
        q.push(root);
        bool isReverse = false;
        while(!q.empty()) {
            int size = q.size();
            vector<int> inter;
            for(int i = 0; i < size; i++) {
                TreeNode *t = q.front();
                q.pop();
                if(!isReverse) {
                    inter.push_back(t->val);
                } else {
                    s.push(t);
                }
                if(t->left != NULL) {
                    q.push(t->left);
                }
                if(t->right != NULL) {
                    q.push(t->right);
                }
            }
            if(isReverse) {
                while(!s.empty()) {
                    inter.push_back(s.top()->val);
                    s.pop();
                }
            }
            isReverse = !isReverse;
            res.push_back(inter);
        }
        return res;
    }
};
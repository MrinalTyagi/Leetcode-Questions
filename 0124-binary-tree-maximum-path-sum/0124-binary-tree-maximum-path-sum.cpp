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
    
    pair<int, int> maxPath(TreeNode *root) {
        if(root == NULL) {
            pair<int, int> r({0, INT_MIN});
            return r;
        }
        auto left = maxPath(root->left);
        auto right = maxPath(root->right);
        pair<int, int> res;
        res.first = max(root->val, max(left.first, right.first) + root->val);
        res.second = max(res.first, max(root->val, max(left.first + right.first + root->val, max(left.second, right.second))));
        return res;
    }
    
    int maxPathSum(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        return maxPath(root).second;
    }
};
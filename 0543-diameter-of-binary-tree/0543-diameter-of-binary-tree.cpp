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
    pair<int, int> helper(TreeNode *root) {
        if(root == NULL) {
            pair<int, int> res;
            res.first = 0;
            res.second = 0;
            return res;
        }
        if(root->left == NULL && root->right == NULL) {
            pair<int, int> res;
            res.first = 1;
            res.second = 1;
            return res;
        }
        auto left = helper(root->left);
        auto right = helper(root->right);
        pair<int, int> res;
        res.first = max(left.first, right.first) + 1;
        res.second = max(left.first + right.first + 1, max(left.second, right.second));
        return res;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        return helper(root).second - 1;
    }
};
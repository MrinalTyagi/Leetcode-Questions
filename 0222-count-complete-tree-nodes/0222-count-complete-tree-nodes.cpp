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
    int countNodes(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int l = 0;
        TreeNode *left = root;
        while(left != NULL) {
            left = left->left;
            l++;
        }
        int r = 0;
        TreeNode *right = root;
        while(right != NULL) {
            right = right->right;
        }
        if(l == r) {
            return 2 * l - 1;
        } else {
            return countNodes(root->left) + countNodes(root->right) + 1;
        }
    }
};
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
    TreeNode *succ(TreeNode *root) {
        root = root->right;
        while(root != NULL && root->left != NULL) {
            root = root->left;
        }
        return root;
    }
    
    TreeNode *pre(TreeNode *root) {
        root = root->left;
        while(root != NULL && root->right != NULL) {
            root = root->right;
        }
        return root;
    }
    
    bool isValidBST(TreeNode* root) {
        if(root == NULL) {
            return true;
        }
        if(root->left != NULL && root->left->val >= root->val) {
            return false;
        }
        if(root->right != NULL && root->right->val <= root->val) {
            return false;
        }
        TreeNode *s = succ(root);
        if(s != NULL && s->val <= root->val) {
            return false;
        }
        TreeNode *p = pre(root);
        if(p != NULL && p->val >= root->val) {
            return false;
        }
        return (isValidBST(root->left) && isValidBST(root->right));
    }
};
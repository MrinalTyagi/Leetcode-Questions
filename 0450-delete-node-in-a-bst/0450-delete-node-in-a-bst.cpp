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
    
    TreeNode *inorderSucc(TreeNode *root) {
        root = root->right;
        while(root->left != NULL) {
            root = root->left;
        }
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) {
            return root;
        }
        if(root->val == key) {
            if(root->left == NULL && root->right == NULL) {
                return NULL;
            } else if(root->left == NULL) {
                return root->right;
            } else if(root->right == NULL) {
                return root->left;
            } else {
                TreeNode *succ = inorderSucc(root);
                if(succ != NULL) {
                    root->val = succ->val;
                    root->right = deleteNode(root->right, succ->val);    
                }
            }
        } else if(key < root->val) {
            root->left = deleteNode(root->left, key);
        } else {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};
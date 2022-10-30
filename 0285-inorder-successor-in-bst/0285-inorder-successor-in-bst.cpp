/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode *root, vector<TreeNode *> &v) {
        if(root == NULL) {
            return;
        }
        inorder(root->left, v);
        v.push_back(root);
        inorder(root->right, v);
    }
    
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        vector<TreeNode *> v;
        inorder(root, v);
        for(int i = 0; i < v.size(); i++) {
            if(v[i] == p && i + 1 < v.size()) {
                return v[i + 1];
            }
        }
        return NULL;
    }
};
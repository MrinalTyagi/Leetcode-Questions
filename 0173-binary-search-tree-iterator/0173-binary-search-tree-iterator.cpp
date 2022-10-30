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
class BSTIterator {
public:
    vector<TreeNode *> in;
    int curr;
    
    void inorder(TreeNode *root, vector<TreeNode *> &v) {
        if(root == NULL) {
            return;
        }
        inorder(root->left, v);
        v.push_back(root);
        inorder(root->right, v);
    }
    
    BSTIterator(TreeNode* root) {
        curr = -1;
        inorder(root, in);
    }
    
    int next() {
        curr++;
        return in[curr]->val;
    }
    
    bool hasNext() { 
        if(curr == -1 || curr < in.size() - 1) {
            return true;
        }
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
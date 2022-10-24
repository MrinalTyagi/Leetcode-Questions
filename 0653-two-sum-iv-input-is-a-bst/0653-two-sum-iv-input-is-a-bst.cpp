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
    void helper(TreeNode *root, vector<int> &res) {
        if(root == NULL) {
            return;
        }
        helper(root->left, res);
        res.push_back(root->val);
        helper(root->right, res);
    }
    
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> res;
        helper(root, res);
        int start = 0, end = res.size() - 1;
        while(start < end) {
            if(res[start] + res[end] == k) {
                return true;
            } else if(res[start] + res[end] < k) {
                start++;
            } else {
                end--;
            }
        }
        return false;
    }
};
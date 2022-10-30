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
    
    TreeNode *helper(vector<int> &preorder, int start, int end) {
        if(start > end) {
            return NULL;
        }
        TreeNode *newNode = new TreeNode(preorder[start]);
        int index = -1;
        for(int i = start + 1; i <= end; i++) {
            if(preorder[i] > newNode->val) {
                index = i;
                break;
            }
        }
        if(index != -1) {
            newNode->left = helper(preorder, start + 1, index - 1);
            newNode->right = helper(preorder, index, end);
        } else {
            newNode->left = helper(preorder, start + 1, end);
        }
        return newNode;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 0) {
            return NULL;
        }
        return helper(preorder, 0, preorder.size() - 1);
    }
};
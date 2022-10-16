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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) {
            return res;
        }
        map<pair<int, int>, vector<int>> m;
        queue<pair<pair<int, int>, TreeNode *>> q;
        q.push({{0, 0}, root});
        m[{0, 0}].push_back(root->val);
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode *t = q.front().second;
                int row = q.front().first.second;
                int col = q.front().first.first;
                q.pop();
                if(t->left != NULL) {
                    q.push({{col - 1, row + 1}, t->left});
                    m[{col - 1, row + 1}].push_back(t->left->val);
                }
                if(t->right != NULL) {
                    q.push({{col + 1, row + 1}, t->right});
                    m[{col + 1, row + 1}].push_back(t->right->val);
                }
            }
        }
        
        map<int, vector<int>> r;
        for(auto x: m) {
            vector<int> v = x.second;
            sort(v.begin(), v.end());
            for(auto y: v) {
                r[x.first.first].push_back(y);
            }
        }
        
        for(auto x: r) {
            res.push_back(x.second);
        }
        
        return res;
    }
};
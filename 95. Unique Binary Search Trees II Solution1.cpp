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
    vector<TreeNode*> generateTrees(int n) {
        if (!n) 
            return {};
        
        return dfs(1, n);
    }
    
    vector<TreeNode*> dfs(int l, int r) {
        if (l > r)
            return {nullptr};
        
        vector<TreeNode*> res;
        for (int i = l; i <= r; ++i) {
            auto left = dfs(l, i - 1), right = dfs(i + 1, r);
            for (auto a : left)
                for (auto b : right) {
                    auto root = new TreeNode(i);
                    root->left = a;
                    root->right = b;
                    res.push_back(root);
                }
        }
        return res;
    }
};

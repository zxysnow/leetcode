/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode *> ans;
        dfs(1, n, ans);
        return ans;
    }
    void dfs(int l, int r, vector<TreeNode *>& tree) {
        if (l > r) {
            tree.push_back(NULL);
            return ;
        }
        for (int i = l; i <= r; i++) {
            vector<TreeNode *> left, right;
            dfs(l, i - 1, left);
            dfs(i + 1, r, right);
            for (int j = 0; j < left.size(); j++) {
                for (int k = 0; k < right.size(); k++) {
                    TreeNode *root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    tree.push_back(root);
                }
            }
        }

    }
};

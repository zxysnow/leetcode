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
    int ans = INT_MIN;
    int Travel(TreeNode *root) {
        if (root == NULL)
            return INT_MIN;
        int l = Travel(root->left);
        int r = Travel(root->right);
        int acc;
        if (l == r && l == INT_MIN) {
            ans = max(ans, root->val);
            return root->val;
        } else {
            if (l == INT_MIN || r == INT_MIN) {
                acc = max(root->val, max(l, r) + root->val);
            } else {
                acc = max(l + root->val, max(r + root->val, root->val));
            }
        }
        int tmp = max(acc, max(l, r));
        if (l != INT_MIN && r != INT_MIN)
            tmp = max(tmp, l + r + root->val);
        ans = max(tmp, ans);
        return acc;
    }
    int maxPathSum(TreeNode *root) {
        Travel(root);
        return ans;
    }
};

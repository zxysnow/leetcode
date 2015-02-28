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
    bool isValidBST(TreeNode *root) {
        long long x = INT_MIN - 1ll;
        return isValid(root, x);
    }
private:
    bool isValid(TreeNode *root, long long &pre) {
        if (root == NULL)
            return true;
        if (root->left == NULL && root->right == NULL) {
            if (root->val <= pre)
                return false;
            pre = root->val;
            return true;
        }
        bool ans = true;
        if (root->left) {
            ans &= isValid(root->left, pre);
            if (!ans || root->val <= pre)
                return false;
        }
        pre = root->val;
        if (root->right) {
            ans &= isValid(root->right, pre);
            if (!ans || root->val >= pre)
                return false;
        }
        return ans;
    }
};

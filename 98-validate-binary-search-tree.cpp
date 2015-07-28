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
        return isValid(root, INT_MIN - 1ll, INT_MAX + 1ll);
    }
    
private :
    bool isValid(TreeNode *root, long long min_val, long long max_val) {
        if (root == NULL)
            return true;
        if (root->val <= min_val || root->val >= max_val)
            return false;
        return isValid(root->left, min_val, root->val) && isValid(root->right, root->val, max_val);
    }
};
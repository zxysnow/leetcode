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
    bool isSym(TreeNode *l, TreeNode *r) {
        if (l == NULL || r == NULL) {
            return l == r;
        }
        if (l->val != r->val) {
            return false;
        }
        return isSym(l->right, r->left) && isSym(l->left, r->right);
    }
    bool isSymmetric(TreeNode *root) {
        return root == NULL ? true : isSym(root->left, root->right);
    }
};

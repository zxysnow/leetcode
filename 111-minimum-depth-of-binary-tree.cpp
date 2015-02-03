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
    int deep;
    void findMinDepth(TreeNode *root, int d) {
        if (root->left == NULL && root->right == NULL) {
            deep = min(deep, d + 1);
            return ;
        }
        if (d + 1 >= deep)
            return ;
        if (root->left)
            findMinDepth(root->left, d + 1);
        if (root->right)
            findMinDepth(root->right, d + 1);
    }
    int minDepth(TreeNode *root) {
        if (root == NULL)
            return 0;
        deep = INT_MAX;
        findMinDepth(root, 0);
        return deep;
    }
};

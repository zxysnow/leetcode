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
    int minDepth(TreeNode *root) {
        if (root == NULL)
            return 0;
        findMinDepth(root, 1);
        return min_depth;
    }

private :
    int min_depth = INT_MAX;
    void findMinDepth(TreeNode *root, int depth) {
        if (root == NULL || depth >= min_depth)
            return ;
        if (root->left == NULL && root->right == NULL) {
            min_depth = min(min_depth, depth);
            return ;
        }
        findMinDepth(root->left, depth + 1);
        findMinDepth(root->right, depth + 1);
    }
};
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
    void flatten(TreeNode *root) {
        tail = root;
        travel(root);
    }

private:
    TreeNode *tail = NULL;
    void travel(TreeNode *root) {
        if (root == NULL)
            return ;
        if (root != tail) {
            tail->right = root;
            tail->left = NULL;
            tail = tail->right;
        }
        TreeNode* right = root->right;
        travel(root->left);
        travel(right);
    }
};

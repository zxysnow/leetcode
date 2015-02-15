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
    void recoverTree(TreeNode *root) {
        travel(root);
        swap(wrong[0]->val, wrong[1]->val);
    }

private:
    vector<TreeNode*> wrong;
    TreeNode *pre = NULL;
    void travel(TreeNode *root) {
        if (root == NULL)
            return ;
        travel(root->left);
        if (pre != NULL && root->val < pre->val) {
            if (wrong.size() == 0) {
                wrong.push_back(pre);
                wrong.push_back(root);
            } else {
                wrong[1] = root;
            }
        }
        pre = root;
        travel(root->right);
    }
};

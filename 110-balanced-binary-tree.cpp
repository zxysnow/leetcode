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
    bool isBalanced(TreeNode *root) {
        int deep = 0;
        return isBal(root, deep);
    }

private:
    bool isBal(TreeNode *root, int &deep) {
        if (root == NULL) {
            deep = 0;
            return true;
        }
        
        int ld = 0, rd = 0;
        if (!isBal(root->left, ld) || !isBal(root->right, rd) || abs(rd - ld) > 1)
            return false;
    
        deep += max(ld, rd) + 1;
        return true;
    }
};

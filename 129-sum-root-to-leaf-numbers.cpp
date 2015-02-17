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
    int sumNumbers(TreeNode *root) {
        int num = 0;
        return travel(root, num);
    }
    
private:
    int ans = 0;
    int travel(TreeNode *root, int num) {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL) {
            return num * 10 + root->val;
        }
        int val = root->val;
        return travel(root->left, num * 10 + val) + travel(root->right, num * 10 + val);
    }
};

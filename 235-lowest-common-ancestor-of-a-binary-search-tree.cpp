/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q)
            return NULL;
        int val = root->val;
        if (min(p->val, q->val) > val)
            return lowestCommonAncestor(root->right, p, q);
        if (max(p->val, q->val) < val)
            return lowestCommonAncestor(root->left, p, q);
        return root;
    }
};
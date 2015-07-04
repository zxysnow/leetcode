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
    int kthSmallest(TreeNode* root, int k) {
        return findKthSmallest(root, k);
    }
    
private :
    int findKthSmallest(TreeNode* root, int& k) {
        if (root == NULL)
            return 0;
        int ans = findKthSmallest(root->left, k);
        if (k == 0)
            return ans;
        if (--k == 0)
            return root->val;
        return findKthSmallest(root->right, k);
    }
};
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        unordered_map<int, int> m;
        for (int i = 0; i < inorder.size(); i++)
            m[inorder[i]] = i;
        return build(0, 0, inorder.size() - 1, preorder, inorder, m);
    }

private:
    TreeNode *build(int x, int l, int r, vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> &m) {
        if (l > r)
            return NULL;
        if (l == r)
            return new TreeNode(inorder[l]);
        TreeNode *root = new TreeNode(preorder[x]);
        root->left = build(x + 1, l, m[preorder[x]] - 1, preorder, inorder, m);
        root->right = build(x + m[preorder[x]] - l + 1, m[preorder[x]] + 1, r, preorder, inorder, m);
    }
};

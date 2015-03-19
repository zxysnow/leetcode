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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        unordered_map<int, int> m;
        for (int i = 0; i < inorder.size(); i++)
            m[inorder[i]] = i;
        return build(inorder.size() - 1, 0, inorder.size() - 1, postorder, inorder, m);
    }

private:
    TreeNode *build(int x, int l, int r, vector<int> &postorder, vector<int> &inorder, unordered_map<int, int> &m) {
        if (l > r)
            return NULL;
        if (l == r)
            return new TreeNode(inorder[l]);
        int pos = m[postorder[x]];
        TreeNode *root = new TreeNode(postorder[x]);
        root->left = build(x - (r - pos + 1), l, pos - 1, postorder, inorder, m);
        root->right = build(x - 1, pos + 1, r, postorder, inorder, m);
    }
};

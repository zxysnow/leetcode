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
        int n = inorder.size();
        for (int i = 0; i < n; i++)
            umap[inorder[i]] = i;
        return build(postorder, n - 1, inorder, 0, n - 1);
    }

private :
    unordered_map<int, int> umap;
    TreeNode* build(vector<int> &postorder, int id, vector<int> &inorder, int l, int r) {
        if (id < 0 || l > r)
            return NULL;
        int pos = umap[postorder[id]];
        TreeNode *root = new TreeNode(postorder[id]);
        root->right = build(postorder, id - 1, inorder, pos + 1, r);
        root->left = build(postorder, id - (r - pos) - 1, inorder, l, pos - 1);
        return root;
    }
};
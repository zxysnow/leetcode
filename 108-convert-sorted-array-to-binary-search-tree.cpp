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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return generateBST(0, num.size() - 1, num);
    }

private :
    TreeNode *generateBST(int l, int r, vector<int> &num) {
        if (l > r)
            return NULL;
        int mid = (l + r) >> 1;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = generateBST(l, mid - 1, num);
        root->right = generateBST(mid + 1, r, num);
        return root;
    }
};

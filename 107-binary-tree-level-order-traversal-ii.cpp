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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > ans;
        if (root == NULL) return ans;
        queue<TreeNode*> pre;
        queue<TreeNode*> next;
        pre.push(root);
        while (!pre.empty()) {
            vector<int> layer;
            while (!pre.empty()) {
                TreeNode *now = pre.front();
                pre.pop();
                layer.push_back(now->val);
                if (now->left)
                    next.push(now->left);
                if (now->right)
                    next.push(now->right);
            }
            ans.push_back(layer);
            swap(pre, next);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

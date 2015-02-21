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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > ans;
        bool order = false;
        if (root == NULL) return ans;
        stack<TreeNode*> pre;
        stack<TreeNode*> next;
        pre.push(root);
        while (!pre.empty()) {
            vector<int> layer;
            while (!pre.empty()) {
                TreeNode *now = pre.top();
                pre.pop();
                layer.push_back(now->val);
                if (!order) {
                    if (now->left)
                        next.push(now->left);
                    if (now->right)
                        next.push(now->right);
                } else {
                    if (now->right)
                        next.push(now->right);
                    if (now->left)
                        next.push(now->left);
                }
            }
            order ^= true;
            ans.push_back(layer);
            swap(pre, next);
        }
        return ans;
    }
};

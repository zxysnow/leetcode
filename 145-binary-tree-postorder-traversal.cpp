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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == NULL)
            return ans;
        stack<TreeNode *> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode *now = stk.top();
            stk.pop();
            ans.push_back(now->val);
            if (now->left)
                stk.push(now->left);
            if (now->right)
                stk.push(now->right);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
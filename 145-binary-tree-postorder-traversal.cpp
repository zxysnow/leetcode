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
    
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ans;
        if (root == NULL)
            return ans;
        stack<TreeNode*> stk;
        stk.push(root);
        TreeNode* pre = root;
        while (!stk.empty()) {
            TreeNode* now = stk.top();
            if ((now->right == pre || now->left == pre) || now->left == NULL && now->right == NULL) {
                ans.push_back(now->val);
                stk.pop();
                pre = now;
                continue;
            }
            if (now->right)
                stk.push(now->right);
            if (now->left)
                stk.push(now->left);
            pre = now;
        }
        return ans;
    }
};

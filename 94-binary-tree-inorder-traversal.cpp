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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        TreeNode *p = root;
        while (p || !stk.empty()) {
            if (p) {
                stk.push(p);
                p = p->left;
            } else{
                p = stk.top();
                ans.push_back(p->val);
                stk.pop();
                p = p->right;
            }
        }
        return ans;
    }
};
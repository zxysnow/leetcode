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
        pushLeft(root);
        while (!stk.empty()) {
            TreeNode *p = stk.top();
            ans.push_back(p->val);
            stk.pop();
            pushLeft(p->right);
        }
        return ans;
    }
private :
    stack<TreeNode*> stk;
    void pushLeft(TreeNode* root) {
        while (root) {
            stk.push(root);
            root = root->left;
        }
    }
};

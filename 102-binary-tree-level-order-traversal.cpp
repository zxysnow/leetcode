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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int len = q.size();
            vector<int> level;
            while (len--) {
                TreeNode *pre = q.front();
                q.pop();
                level.push_back(pre->val);
                if (pre->left)
                    q.push(pre->left);
                if (pre->right)
                    q.push(pre->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};
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
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> layer;
            int len = q.size();
            while (len--) {
                TreeNode* pre = q.front();
                q.pop();
                layer.push_back(pre->val);
                if (pre->left != NULL)
                    q.push(pre->left);
                if (pre->right != NULL)
                    q.push(pre->right);
            }
            ans.push_back(layer);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
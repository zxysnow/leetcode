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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            ans.push_back(q.back()->val);
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode *now = q.front();
                q.pop();
                if (now->left)
                    q.push(now->left);
                if (now->right)
                    q.push(now->right);
            }
        }
        return ans;
    }
};

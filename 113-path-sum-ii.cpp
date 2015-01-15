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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        findPath(root, sum);
        return ans;
    }
    
private:
    vector<vector<int> > ans;
    vector<int> now;
    void findPath(TreeNode *root, int sum) {
        if (root == NULL)
            return ;
        now.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            if (sum - root->val == 0)
                ans.push_back(now);
        } else {
            findPath(root->left, sum - root->val);
            findPath(root->right, sum - root->val);
        }
        now.pop_back();
    }
};

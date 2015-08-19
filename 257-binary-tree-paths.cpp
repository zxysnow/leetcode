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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        findPath(root, "", ans);
        return ans;
    }

private :
    void findPath(TreeNode* root, string path, vector<string> &ans) {
        if (root == nullptr)
            return ;
        path += to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(path);
            return ;
        }
        path += "->";
        if (root->left)
            findPath(root->left, path, ans);
        if (root->right)
            findPath(root->right, path, ans);
    }
};
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL || root->left == NULL && root->right == NULL) 
            return ;
        if (root->left && root->right) {
            root->left->next = root->right;
        }
        TreeLinkNode *right = root->right;
        if (right == NULL)
            right = root->left;
        for (TreeLinkNode *p = root->next; p; p = p->next) {
            if (p->left) {
                right->next = p->left;
                break;
            }
            if (p->right) {
                right->next = p->right;
                break;
            }
        }
        connect(root->right);
        connect(root->left);
    }
};
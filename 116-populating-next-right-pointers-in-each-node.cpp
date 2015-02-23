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
        root->left->next = root->right;
        root->right->next = root->next == NULL ? NULL : root->next->left;
            
        connect(root->left);
        connect(root->right);
    }
};

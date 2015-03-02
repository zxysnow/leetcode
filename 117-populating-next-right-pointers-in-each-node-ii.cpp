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
        if (root == NULL)
            return ;
        queue<TreeLinkNode* > pre;
        queue<TreeLinkNode* > next;
        pre.push(root);
        while (!pre.empty()) {
            while (!pre.empty()) {
                TreeLinkNode *now = pre.front();
                pre.pop();
                if (pre.empty()) {
                    now->next = NULL;
                } else {
                    now->next = pre.front();
                }
                if (now->left)
                    next.push(now->left);
                if (now->right)
                    next.push(now->right);
            }
            swap(pre, next);
        }  
    }
};

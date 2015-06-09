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
    int countNodes(TreeNode* root) {
        if (root == NULL)
            return 0;
        int h = calculateH(root);
        h--;
        int sum = (1 << h) - 1;
        int l = 1, r = (1 << h);
        int mid = 0;
        while (l < r) {
            mid = (l + r) >> 1;
            if (check(mid, h - 1, root)) {
				l = mid + 1;
			} else {
                r = mid;
			}
        }
        return sum + r;
    }

private :
    bool check(int path, int h, TreeNode *root) {
        if (h == -1) {
            return root != NULL;
        }
        if (root == NULL) {
            return false;
        }
        if (path & (1 << h)) {
            return check(path, h - 1, root->right);
        }
        return check(path, h - 1, root->left);
    }
    int calculateH(TreeNode *root) {
        TreeNode *head = root;
        int h = 0;
        while (head) {
            h++;
            head = head->left;
        }
        return h;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        int cnt = 0;
        ListNode *p = head;
        while (p) {
            cnt++;
            p = p->next;
        }
        return toBST(head, cnt);

    }
private:
    TreeNode *toBST(ListNode *&head, int n) {
        if (n == 0)
            return NULL;
        int l = (n - 1) / 2, r = n - l - 1;
        TreeNode *left = toBST(head, l);
        TreeNode *root = new TreeNode(head->val);
        head = head->next;
        root->left = left;
        root->right = toBST(head, r);
        return root;
    }
};

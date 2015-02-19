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
        if (head == NULL)
            return NULL;
        if (head->next == NULL)
            return new TreeNode(head->val);
        ListNode *mid = findMid(head);
        TreeNode *root = new TreeNode(mid->next->val);
        ListNode *next = mid->next->next;
        mid->next = NULL;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(next);
        return root;
    }
private:
    ListNode* findMid(ListNode* head) {
        ListNode *first = head, *second = head->next;
        while (second) {
            second = second->next;
            if (second == NULL || second->next == NULL)
                break;
            second = second->next;
            first = first->next;
        }
        return first;
    }
};

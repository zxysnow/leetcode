/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *p = head;
        while (p && p->next != NULL) {
            ListNode *t = p;
            while (p->next != NULL && p->next->val == t->val)
                p = p->next;
            t->next = p->next;
            p = t->next;
        }
        return head;
    }
};

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *h = new ListNode(0);
        h->next = head;
        ListNode *t = h;
        while (t != NULL && t->next != NULL) {
            if (t->next->val == val) {
                t->next = t->next->next;
            } else {
                t = t->next;
            }
        }
        return h->next;
    }
};

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
    ListNode *swapPairs(ListNode *head) {
        ListNode ans = ListNode(0);
        ans.next = head;
        ListNode *p = &ans;
        while (p != NULL && p->next != NULL && p->next->next != NULL) {
                ListNode* q = p->next->next;
                p->next->next = q->next;
                q->next = p->next;
                p->next = q;
                p = p->next->next;
        }
        return ans.next;
    }
};

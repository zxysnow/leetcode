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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode ans(0);
        ans.next = head;
        ListNode *p = &ans, *start = NULL, *last = NULL;
        for (int i = 0; i < m - 1; i++)
            p = p->next;
        last = start = p->next;
        for (int i = m; i <= n; i++) {
            ListNode *t = last;
            last = last->next;
            t->next = p->next;
            p->next = t;
        }
        start->next = last;
        return ans.next;
    }
};
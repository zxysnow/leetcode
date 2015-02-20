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
    void reorderList(ListNode *head) {
        int cnt = 0;
        for (ListNode *p = head; p; p = p->next)
            cnt++;
        if (cnt <= 2)
            return ;
        int k = (cnt - 1) / 2;
        ListNode *p = head;
        while (k--) {
            p = p->next;
        }
        ListNode *tail = p->next;
        while (tail->next) {
            ListNode *t = tail->next->next;
            tail->next->next = p->next;
            p->next = tail->next;
            tail->next = t;
        }
        
        tail = p;
        p = head;
        while (tail->next) {
            if (tail->next == p->next) {
                tail = tail->next;
                continue;
            }
            ListNode *t = tail->next->next;
            tail->next->next = p->next;
            p->next = tail->next;
            tail->next = t;
            p = p->next->next;
        }
    }
};

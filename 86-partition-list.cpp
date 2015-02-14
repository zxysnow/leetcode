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
    ListNode *partition(ListNode *head, int x) {
        ListNode ans = ListNode(0);
        ans.next = head;
        ListNode *tail = &ans, *p = NULL;
        if (head == NULL)
            return head;
        while (tail->next != NULL && tail->next->val < x)
                tail = tail->next;
        if (tail->next == NULL)
            return head;
        p = tail;
        while (p && p->next != NULL) {
            if (p->next->val < x && p->next != tail->next) {
                ListNode *t = tail->next;
                tail->next = p->next;
                p->next = p->next->next;
                tail = tail->next;
                tail->next = t;
            } else {
                p = p->next;
            }
        }
        
        return ans.next;
    }
};

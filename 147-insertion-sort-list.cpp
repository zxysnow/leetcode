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
    ListNode *insertionSortList(ListNode *head) {
        ListNode ans = ListNode(0);
        
        while (head) {
            ListNode *p = &ans;
            while (p->next != NULL && p->next->val < head->val) {
                p = p->next;
            }
            ListNode *t = head->next;
            head->next = p->next;
            p->next = head;
            head = t;
        }
        return ans.next;
    }
};

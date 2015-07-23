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
        ListNode left(0), right(0);
        ListNode *lp = &left, *rp = &right;
        for (; head; head = head->next) {
            if (head->val < x) {
                lp->next = head;
                lp = lp->next;
            } else {
                rp->next = head;
                rp = rp->next;
            }
        }
        rp->next = NULL;
        lp->next = right.next;
        return left.next;
    }
};
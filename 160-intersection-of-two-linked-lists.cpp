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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lena = 0, lenb = 0;
        for (ListNode *head = headA; head; head = head->next)
            lena++;
        for (ListNode *head = headB; head; head = head->next)
            lenb++;
        for (int i = 0; i < lena - lenb; i++)
            headA = headA->next;
        for (int i = 0; i < lenb - lena; i++)
            headB = headB->next;
        for (int i = 0; i < min(lena, lenb); i++) {
            if (headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};

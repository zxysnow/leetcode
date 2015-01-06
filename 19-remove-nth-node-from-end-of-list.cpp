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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode* first = head;
        ListNode* second = head;
        ListNode* pre = head;
        for(int i = 0; i < n; i++)
            first = first->next;
        if( first == NULL )
            return head->next;
        while( first ) {
            pre = second;
            second = second->next;
            first = first->next;
        }
        pre->next = second->next;
        return head;
    }
};

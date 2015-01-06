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
        if( head == NULL )
            return head;
        ListNode* ans = new ListNode(0);
        ans->next = head;
        ListNode* pre = ans;
        ListNode* cur = head;
        while( cur ) {
            while( cur->next && cur->next->val == pre->next->val ) {
                cur = cur->next;
            }
            if( pre->next == cur ) {
                pre = pre->next;
            } else {
                pre->next = cur->next;
            }
            cur = cur->next;
        }
        return ans->next;
    }
};

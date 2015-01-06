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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int carry = 0;
        ListNode *ans = new ListNode(0);
        ListNode *head = ans;

        while( l1 || l2 || carry ) {
            int num = -1;
            if( l1 ) {
                num = l1 -> val;
                l1 = l1 -> next;
            }
            if( l2 ) {
                if( num == -1 )
                    num = 0;
                num += l2 -> val;
                l2 = l2 -> next;
            }
            if( num == -1 ) {
                ans -> next = new ListNode(carry);
                carry = 0;
            } else {
                ans -> next = new ListNode((num + carry) % 10);
                carry = (num + carry) / 10;
            }
            ans = ans -> next;
        }
        return head -> next;
    }
};

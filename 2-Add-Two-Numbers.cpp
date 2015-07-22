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
        ListNode ans(0);
        ListNode *sum = &ans;
        int carry = 0;
        while (l1 || l2 || carry) {
            int s = carry;
            if (l1) {
                s += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                s += l2->val;
                l2 = l2->next;
            }
            carry = s / 10;
            sum->next = new ListNode(s % 10);
            sum = sum->next;
        }
        return ans.next;
    }
};
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
    ListNode * deleteDuplicates(ListNode *head) {
        ListNode ans(0);
        ans.next = head;
        ListNode *pre = &ans;
        while (pre->next) {
            head = pre->next;
            int now = head->val;
            if (head->next && head->next->val == now) {
                while (head->next && head->next->val == now)
                    head = head->next;
                pre->next = head->next;
            } else {
                pre = pre->next;
            }
        }
        return ans.next;
    }
};
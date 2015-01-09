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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL || k == 0)
            return head;
        ListNode ans = ListNode(0);
        ans.next = head;
        int len = 1;
        while (head->next) {
            head = head->next;
            len++;
        }
        k = k % len;
        head->next = ans.next;
        for (int i = 0; i < len - k; i++) {
            head = head->next;
        }
        ans.next = head->next;
        head->next = NULL;
        return ans.next;
    }
};

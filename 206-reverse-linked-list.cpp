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
    ListNode* reverseList(ListNode* head) {
        reverse(head);
        return ans;
    }

private :
    ListNode* ans = NULL;
    ListNode* reverse(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            ans = head;
            return head;
        }
        ListNode* p = reverse(head->next);
        head->next = NULL;
        p->next = head;
        return p->next;
    }
};

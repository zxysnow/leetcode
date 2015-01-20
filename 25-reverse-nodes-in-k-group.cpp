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
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode ans = ListNode(0);
        ans.next = head;
        ListNode *pre = &ans, *now = head, *tail = &ans;
        int cnt = 0;
        while (now) {
            now = now->next;
            cnt++;
        }
        int tmp = cnt / k * k;
        cnt = 1;
        while (cnt <= tmp) {
            if (cnt % k == 1) {
                pre = tail;
                tail = head;
            } else {
                ListNode* t = head;
                tail->next = head->next;
                t->next = pre->next;
                pre->next = t;
                head = tail;
            }
            cnt++;
            head = head->next;
        }
        return ans.next;
    }
};

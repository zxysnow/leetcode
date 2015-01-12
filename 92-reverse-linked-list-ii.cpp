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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode ans = ListNode(0);
        ans.next = head;
        ListNode *hm =  &ans, *hn, *tmp, *last;
        for (int i = 0; i < m - 1; i++)
            hm = hm->next;
        last = hm->next;
        hn = hm->next;
        hm->next= NULL;
        for (int i = m; i <= n; i++) {
            tmp = hn->next;
            hn->next = hm->next;
            hm->next = hn;
            hn = tmp;
        }
        last->next = hn;
        return ans.next;
    }
};

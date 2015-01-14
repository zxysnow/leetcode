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
    struct cmp{ 
        bool operator()(const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        ListNode ans = ListNode(0);
        ListNode* ahead = &ans;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i])
                q.push(lists[i]);
        }
        while (!q.empty()){
            ListNode* head = q.top();
            q.pop();
            ahead->next = head;
            if (head->next != NULL)
                q.push(head->next);
            ahead = ahead->next;
            ahead->next = NULL;
        }
        return ans.next;
    }
};

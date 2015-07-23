class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: void
     */
    void reorderList(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return ;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *t = slow->next;
        ListNode *right = NULL;
        while (t) {
            ListNode *p = t->next;
            t->next = right;
            right = t;
            t = p;
        }
        slow->next = NULL;
        t = head;
        while (right) {
            ListNode *p = t->next;
            t->next = right;
            right = right->next;
            t->next->next = p;
            t = t->next->next;
        }
    }
};


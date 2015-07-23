class Solution {
public:
    ListNode *sortList(ListNode *head) {
        int len = calculateLength(head);
        return mergeSort(head, len);
    }

private :
    ListNode *mergeSort(ListNode *&head, int len) {
        if (len == 0)
            return NULL;
        if (len == 1) {
            ListNode *ans = head;
            head = head->next;
            ans->next = NULL;
            return ans;
        }
        ListNode *left = mergeSort(head, len / 2);
        ListNode *right = mergeSort(head, len - len / 2);
        return merge(left, right);
    }
    ListNode *merge(ListNode *left, ListNode *right) {
        ListNode *head = new ListNode(0);
        int i = 0, k = 0;
        ListNode *p = head;
        for (;left || right; p = p->next) {
            if (left == NULL || right && right->val < left->val) {
                p->next = right;
                right = right->next;
            } else {
                p->next = left;
                left = left->next;
            }
        }
        p->next = NULL;
        return head->next;
    }
    int calculateLength(ListNode *head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }
};


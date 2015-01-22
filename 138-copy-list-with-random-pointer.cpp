/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL)
            return NULL;
        RandomListNode ans = RandomListNode(0);
        RandomListNode *p, *t;
        for (t = head; t != NULL;) {
            p = new RandomListNode(t->label);
            if (ans.next == NULL)
                ans.next = p;
            p->next = t->next;
            t->next = p;
            t = t->next->next;
        }
        for (t = head; t != NULL;) {
            t->next->random = t->random == NULL ? NULL : t->random->next;
            t = t->next->next;
        }
        for (t = head; t != NULL;) {
            p = t->next;
            t->next = t->next->next;
            p->next = t->next == NULL ? NULL : t->next->next;
            t = t->next;
        }

        return ans.next;
    }
};

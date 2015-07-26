class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL)
            return NULL;
        RandomListNode *cp = NULL;
        RandomListNode *p = head;
        for (p = head; p;) {
            RandomListNode *t = new RandomListNode(p->label);
            t->next = p->next;
            p->next = t;
            p = p->next->next;
        }
        cp = head->next;
        for (p = head; p;) {
            p->next->random = p->random ? p->random->next : NULL;
            p = p->next->next;
        }
        for (p = head; p; p = p->next) {
            RandomListNode *t = p->next;
            p->next = p->next->next;
            t->next = p->next == NULL ? NULL : p->next->next;
        }
        return cp;
    }
};

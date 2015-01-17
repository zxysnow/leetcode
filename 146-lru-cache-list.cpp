struct Node {
    int val;
    Node *next;
    Node(int key, int x) : key(key), val(x), next(NULL) {}
	int key;
};
 
class LRUCache{
public:
    LRUCache(int capacity) {
		head = new Node(-1, -1);
		tail = head;
        cap = capacity;
        cnt = 0;
    }
    
    int get(int key) {
        if (m.count(key) == 0)
            return -1;
        set(key, m[key]->next->val);
        return m[key]->next->val;
    }
    
    void set(int key, int value) {
        if (m.count(key) == 0) {
            if (cap == m.size()) {
                m.erase(head->next->key);
                if (head->next == tail)
                    tail = head;
                head->next = head->next->next;
				if (head->next) {
					m[head->next->key] = head;
				}
            }
            tail->next = new Node(key, value);
            m[key] = tail;
            tail = tail->next;
        } else {
			if (tail == m[key]->next) {
				tail->val = value;
				return ;
			}
            Node* pre = m[key];
            Node* now = pre->next;
            pre->next = now->next;
			if (now->next) {
				m[now->next->key] = pre;
			}
            tail->next = now;
            now->next = NULL;
            m[key] = tail;
            now->val = value;
            tail = now;
        }
    }
    
private:
    int cap, cnt;
    map<int, Node*> m; 
    Node *head;
    Node *tail;
};

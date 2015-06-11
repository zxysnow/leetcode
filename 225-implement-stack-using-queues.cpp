class Stack {
public:
    vector<int> v;
    // Push element x onto stack.
    void push(int x) {
        v.push_back(x);
    }

    // Removes the element on top of the stack.
    void pop(void) {
        v.pop_back();
    }

    // Get the top element.
    int top(void) {
        return v.back();
    }

    // Return whether the stack is empty.
    bool empty(void) {
        return v.size() == 0;
    }
};

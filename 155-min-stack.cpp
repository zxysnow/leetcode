class MinStack {
public:
    void push(int x) {
        all.push(x);
        if (minone.empty() || x <= minone.top()) {
            minone.push(x);
        }
    }

    void pop() {
        if (minone.top() == all.top()) {
            minone.pop();
        }
        all.pop();
    }

    int top() {
        return all.top();
    }

    int getMin() {
        return minone.top();
    }
    
private:
    stack<int> minone;
    stack<int> all;
};

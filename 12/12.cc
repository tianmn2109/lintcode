class MinStack {
public:
    stack<int> stk;
    stack<int> minStk;
    MinStack() {
        // do initialization if necessary
    }

    void push(int number) {
        // write your code here
        stk.push(number);
        if (!minStk.empty() && minStk.top() < number) {
            minStk.push(minStk.top());
        }
        else {
            minStk.push(number);
        }
    }

    int pop() {
        // write your code here
        minStk.pop();
        int ret = stk.top();
        stk.pop();
        return ret;
    }

    int min() {
        // write your code here
        return minStk.top();
    }
};



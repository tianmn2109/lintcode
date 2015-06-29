class Queue {
public:
    stack<int> stack1;
    stack<int> stack2;

    Queue() {
        // do intialization if necessary
    }

    void push(int element) {
        // write your code here
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        stack1.push(element);
        while (!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
    }
    
    int pop() {
        // write your code here
        int ret = stack1.top();
        stack1.pop();
        return ret;
    }

    int top() {
        // write your code here
        return stack1.top();
    }
};

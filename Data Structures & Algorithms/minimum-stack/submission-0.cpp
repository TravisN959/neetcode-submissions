class MinStack {
public:

    //using stack for min stack
    // use first stack to keep track of stack
    //use second stack to keep track of min, if smaller than top then push
    std::stack<int> stack;
    std::stack<int> minStack;
    MinStack() {
        
    }
    
    void push(int value) {
        stack.push(value);
        if(minStack.empty() || minStack.top() >= value)
            minStack.push(value);
    }
    
    void pop() {
        if(minStack.top() == stack.top()) //removes if the top value is smallest
            minStack.pop();
        stack.pop(); //Equals same value so pop
    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
 
class MinStack {

private:

    stack<int> myStack;
    stack<int> myMinStack;
    int currMin = INT_MAX;

public:
    MinStack() {

    }
    
    void push(int val) {

        myStack.push(val);
        myMinStack.push(min(currMin, val));
        currMin = myMinStack.top();
    }
    
    void pop() {
        myStack.pop();
        myMinStack.pop();
        if(myMinStack.empty()) currMin = INT_MAX;
        else currMin = myMinStack.top();
    }
    
    int top() {

        return myStack.top();
    }
    
    int getMin() {
        
        return myMinStack.top();
    }
};

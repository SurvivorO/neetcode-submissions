class MinStack {

private:
    int minm = INT_MAX;
    vector<int> myStack;

public:
    MinStack() {

    }
    
    void push(int val) {

        myStack.push_back(val);
        minm = min(minm, val);
    }
    
    void pop() {
        if(minm == top()) {
            minm = INT_MAX;
            for(int i = 0; i < myStack.size() - 1; i++){
                minm = min(minm, myStack[i]);
            }
        }
        myStack.erase(myStack.end() - 1);
    }
    
    int top() {
        int num = *(myStack.end() - 1);
        return num;
    }
    
    int getMin() {
        
        return minm;
    }
};

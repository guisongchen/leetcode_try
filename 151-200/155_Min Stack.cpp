/*

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
 

Example:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.

*/

// keypoints:
// 1. we only need to getMin, not need to popMin, this make it easier to solver
// 2. we need space to hold min and second-min value
//
// solution 1. we can use two stacks to do this, one stack is normal, another keep history-record of min
// solution 2. we use minVal to keep min, and use the one behind top to hold second-min value  


// solution 1

class MinStack {
public:
    MinStack() {}    
    void push(int x) {
        s1.push(x);
        if (s2.empty() || x <= s2.top()) s2.push(x);
    }    
    void pop() {
        if (s1.top() == s2.top()) s2.pop();
        s1.pop();
    }  
    int top() {
        return s1.top();
    }    
    int getMin() {
        return s2.top();
    }
    
private:
    stack<int> s1, s2;
};

// solution 2

class MinStack {
public:
    /** initialize your data structure here. */
    
    // keypoint: NOT ONLY push minVal into stack, BUT ALSO keep a copy outside
    // also we keep 2nd minVal stay behind minVal
    // big picture:
    // | min   |
    // |2nd min|
    // |normal n|
    // |noraml m|
    // |2nd min|
    // |3nd min|
    // |3nd min|
    // |4nd min|
    MinStack() : minVal(INT_MAX) {}
    
    void push(int x) {
        
        // if minVal needs update
        // must be "<=" here, since may have more than one minVal element (have same value)
        if (x <= minVal) {
            // prev minVal is not minimize, push stack
            st.push(minVal);
            // keep a copy of current minVal outside
            minVal = x;
        }
        
        // normally push
        st.push(x);
    }
    
    void pop() {
        if (st.top() == minVal) {
            st.pop();
            minVal = st.top();
            st.pop();
        } else {
            st.pop();
        }
        
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minVal;
    }

private:
    int minVal;
    stack<int> st;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

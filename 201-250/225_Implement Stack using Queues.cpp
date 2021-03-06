/*

Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Example:

MyStack stack = new MyStack();

stack.push(1);
stack.push(2);  
stack.top();   // returns 2
stack.pop();   // returns 2
stack.empty(); // returns false
Notes:

You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).

*/

// keypoints:
// queue: FIFO, stack: FILO
// (1) using 1 queue
// 1. when push x, push x into queue
// 2. repeat push(front) and pop (n-1) times, so nums before x now behind it
// 2. pop and top and empty not change

// (2) using 2 queue(use one queue to keep top element)
// 1. when push x, push x into queue 2(queue 2 only keep top num, aka the last push num)
//    if queue 2 size > 1, push queue 2 front to queue 1, queue 2 pop
// 2. when pop, queue 2 return and pop
// 3. when top, if queue 2 not empty, return front
//    if empty, queue q repeat push(front) and pop (n-1) times, so nums before last num now behind it
//    push queue 1 front to queue 2, then queue 1 pop
// 4. if queue 1 and queue 2 botn empty, return empty


// solution 1: use 1 queue

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {}
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        int n = q.size();
        while (n-- > 1) {
            int t = q.front();
            q.pop();
            q.push(t);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int t = q.front();
        q.pop();
        return t;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
    
private:
    queue<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
 
 
 
 // solution 2: use two queue
 
 class MyStack {
public:
    MyStack() {}
    void push(int x) {
        q2.push(x);
        while (q2.size() > 1) {
            q1.push(q2.front()); q2.pop();
        }
    }
    int pop() {
        int x = top(); q2.pop();
        return x;
    }
    int top() {
        if (q2.empty()) {
            for (int i = 0; i < (int)q1.size() - 1; ++i) {
                q1.push(q1.front()); q1.pop();
            }
            q2.push(q1.front()); q1.pop();
        }
        return q2.front();
    }
    bool empty() {
        return q1.empty() && q2.empty();
    }
private:
    queue<int> q1, q2;
};

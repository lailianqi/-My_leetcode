#include <stack>
using namespace std;
//比较简单，两个堆栈实现
//感觉效率非常的差
// leetcode上类似的解法 效率也一般
// https://discuss.leetcode.com/topic/28514/easy-java-solution-just-edit-push-method
class MyQueue {
  public:
    /** Initialize your data structure here. */
    MyQueue() {}

    /** Push element x to the back of queue. */
    void push(int x) { myStack.push(x); }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while (!myStack.empty()) {
            myStackTemp.push(myStack.top());
            myStack.pop();
        }
        int x = myStackTemp.top();
        myStackTemp.pop();
        while (!myStackTemp.empty()) {
            myStack.push(myStackTemp.top());
            myStackTemp.pop();
        }
        return x;
    }

    /** Get the front element. */
    int peek() {
        while (!myStack.empty()) {
            myStackTemp.push(myStack.top());
            myStack.pop();
        }
        int x = myStackTemp.top();
        while (!myStackTemp.empty()) {
            myStack.push(myStackTemp.top());
            myStackTemp.pop();
        }
        return x;
    }

    /** Returns whether the queue is empty. */
    bool empty() { return myStack.empty(); }

  private:
    stack<int> myStack;
    stack<int> myStackTemp;
};

// leetcode上比较好的解法  代码比较优雅
// https://discuss.leetcode.com/topic/17974/short-o-1-amortized-c-java-ruby
class MyQueue_0 {
  public:
    /** Initialize your data structure here. */
    MyQueue_0() {}

    /** Push element x to the back of queue. */
    void push(int x) { input.push(x); }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x = peek();
        output.pop();
        return x;
    }

    /** Get the front element. */
    int peek() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() { return input.empty() && output.empty(); }

  private:
    stack<int> input;
    stack<int> output;
};
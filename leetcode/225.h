#include <queue>
#include <deque>
using namespace std;
//自己写的方法，用的deque
class MyStack {
  private:
    deque<int> myQueue;

  public:
    /** Initialize your data structure here. */
    MyStack() {}

    /** Push element x onto stack. */
    void push(int x) { myQueue.push_back(x); }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = myQueue.back();
        myQueue.pop_back();
        return x;
    }

    /** Get the top element. */
    int top() { return myQueue.back(); }

    /** Returns whether the stack is empty. */
    bool empty() { return myQueue.empty(); }
};

//其实本题不能用deque 应该用queue来做
class MyStack_0 {
  private:
    queue<int> myQueue;

  public:
    /** Initialize your data structure here. */
    MyStack_0() {}

    /** Push element x onto stack. */
    void push(int x) { myQueue.push(x); }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = myQueue.back();
        int len = myQueue.size();
        for (int i = 0; i < len - 1; ++i) {
            myQueue.push(myQueue.front());
            myQueue.pop();
        }
        myQueue.pop();
        return x;
    }

    /** Get the top element. */
    int top() { return myQueue.back(); }

    /** Returns whether the stack is empty. */
    bool empty() { return myQueue.empty(); }
};
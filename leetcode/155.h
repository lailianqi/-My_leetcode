#include <vector>
#include <algorithm>
#include <stack>
#include <climits>
using namespace std;

// You are here!
// Your runtime beats 37.57 % of cpp submissions.
//自己原始的写法，效率并不好
class MinStack {
  public:
    /** initialize your data structure here. */
    vector<int> stack;
    int minNum;
    MinStack() { minNum = INT_MAX; }

    void push(int x) {
        minNum = min(minNum, x);
        stack.push_back(x);
    }

    void pop() {
        if (stack.empty()) {
            return;
        }
        if (top() == minNum) {
            stack.pop_back();
            minNum = findMinNum();
        } else {
            stack.pop_back();
        }
    }
    int top() { return stack.back(); }

    int getMin() { return minNum; }
    int findMinNum() {
        int minNum = INT_MAX;
        for (int i = 0; i < stack.size(); i++) {
            minNum = min(minNum, stack[i]);
        }
        return minNum;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

// leetcode的答案
// https://discuss.leetcode.com/topic/7020/java-accepted-solution-using-one-stack?page=1

class MinStack_0 {
  public:
    /** initialize your data structure here. */
    MinStack_0() : minNum(INT_MAX) {}
    stack<int> m_stack;
    int minNum;

    void push(int x) {
        if (x <= minNum) {
            m_stack.push(minNum);
            minNum = x;
        }
        m_stack.push(x);
    }

    void pop() {
        if (m_stack.top() == minNum) {
            m_stack.pop();
            minNum = m_stack.top();
        }
        m_stack.pop();
    }
    int top() { return m_stack.top(); }

    int getMin() { return minNum; }
};

class MinStack_1 {
  public:
    /** initialize your data structure here. */
    MinStack_1() {}
    stack<int> stack1;
    stack<int> stack2;
    void push(int x) {
        stack1.push(x);
        if (stack2.empty() || x <= getMin()) {
            stack2.push(x);
        }
    }
    void pop() {
        if (stack1.top() == getMin())
            stack2.pop();
        stack1.pop();
    }
    int top() { return stack1.top(); }
    int getMin() { return stack2.top(); }
};
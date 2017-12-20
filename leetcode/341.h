#include <vector>
#include <deque>
#include <stack>
using namespace std;

//这道题感觉自己没有想到点子上

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than
    // a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a
    // single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a
    // nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

// leetcode的答案 写的非常的好
// https://discuss.leetcode.com/topic/42042/simple-java-solution-using-a-stack-with-explanation
class NestedIterator {
  public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; i--) {
            nestedStack.push(nestedList[i]);
        }
    }

    int next() {
        int temp = nestedStack.top().getInteger();
        nestedStack.pop();
        return temp;
    }

    bool hasNext() {
        while (!nestedStack.empty()) {
            NestedInteger curr = nestedStack.top();
            if (curr.isInteger()) {
                return true;
            }
            nestedStack.pop();
            for (int i = curr.getList().size() - 1; i >= 0; i--) {
                nestedStack.push(curr.getList()[i]);
            }
        }
        return false;
    }

  private:
    stack<NestedInteger> nestedStack;
};

namespace st {
// https://discuss.leetcode.com/topic/41870/real-iterator-in-python-java-c/2?page=1
class NestedIterator {
  public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        begins.push(nestedList.begin());
        ends.push(nestedList.end());
    }

    int next() { return (begins.top()++)->getInteger(); }

    bool hasNext() {
        while (begins.size()) {
            if (begins.top() == ends.top()) {
                begins.pop();
                ends.pop();
            } else {
                auto x = begins.top();
                if (x->isInteger())
                    return true;
                begins.top()++;
                begins.push(x->getList().begin());
                ends.push(x->getList().end());
            }
        }
        return false;
    }

  private:
    stack<vector<NestedInteger>::iterator> begins, ends;
};
};
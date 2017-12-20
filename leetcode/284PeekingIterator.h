#include <vector>
using namespace std;

class Iterator {
    struct Data;
    Data *data;

  public:
    Iterator(const vector<int> &nums);
    Iterator(const Iterator &iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};
/*
class PeekingIterator : public Iterator {
  public:
    PeekingIterator(const vector<int> &nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
    }
    // Returns the next element in the iteration without advancing the iterator.
    int peek() { return Iterator(*this).next(); }
    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() { return Iterator::next(); }
    bool hasNext() const { return Iterator::hasNext(); }
};
*/
// leetcode的答案
// https://discuss.leetcode.com/topic/24883/concise-java-solution
class PeekingIterator : public Iterator {
  private:
    int nextNum;
    bool m_hasNext;

  public:
    PeekingIterator(const vector<int> &nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        m_hasNext = Iterator::hasNext();
        if (m_hasNext) {
            nextNum = Iterator::next();
        }
    }
    // Returns the next element in the iteration without advancing the iterator.
    int peek() { return nextNum; }
    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        int temp = nextNum;
        m_hasNext = Iterator::hasNext();
        if (m_hasNext)
            nextNum = Iterator::next();
        return temp;
    }
    bool hasNext() const { return m_hasNext; }
};
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
//自己的写法写的，感觉这题这样写太简单了
class MedianFinder {
  public:
    /** initialize your data structure here. */
    MedianFinder() {}

    void addNum(int num) {
        array.insert(lower_bound(array.begin(), array.end(), num), num);
    }

    double findMedian() {
        if (array.size() & 1) {
            return array[array.size() / 2];
        } else {
            return (array[array.size() / 2] + array[array.size() / 2 - 1]) /
                   2.0;
        }
    }

  private:
    vector<int> array;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */

// leetcode的答案
// http://www.cnblogs.com/grandyang/p/4896673.html
//
class Solution {
    class MedianFinder {
      public:
        /** initialize your data structure here. */
        MedianFinder() {}
        void addNum(int num) {
            small.push(num);
            large.push(-small.top());
            small.pop();
            if (small.size() < large.size()) {
                small.push(-large.top());
                large.pop();
            }
        }
        double findMedian() {
            return small.size() > large.size()
                       ? small.top()
                       : (-large.top() + small.top()) / 2.0;
        }

      private:
        priority_queue<long> small, large;
    };
};
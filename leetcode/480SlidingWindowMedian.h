#include <algorithm>
#include <iterator>
#include <queue>
#include <set>
#include <vector>
using namespace std;
//题目的意思理解错了 所以下面的第一个答案是错的
class Solution {
  public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k) {
        int left = 0, right = 0;
        vector<double> res;
        for (int i = 0; i < nums.size(); i++) {
            if (right - left + 1 < k) {
                right++;
            } else {
                int midIndex = (left + right) / 2;
                if (k & 1) {
                    res.push_back((double)nums[midIndex]);
                } else {
                    res.push_back(
                        (double)(nums[midIndex] + nums[midIndex + 1]) / 2);
                }
                left++, right++;
            }
        }
        return res;
    }
};

// leetcode 的答案 sp大神的解法
// https://discuss.leetcode.com/topic/74963/o-n-log-k-c-using-multiset-and-updating-middle-iterator
// https://discuss.leetcode.com/topic/74963/o-n-log-k-c-using-multiset-and-updating-middle-iterator/10
class Solution_0 {
  public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k) {
        multiset<int> window(nums.begin(), nums.begin() + k);
        auto mid = next(window.begin(), k / 2);
        vector<double> medians;
        for (int i = k;; i++) {
            medians.push_back((double(*mid) + *prev(mid, 1 - k % 2)) / 2);
            if (i == nums.size())
                return medians;
            window.insert(nums[i]);
            if (nums[i] < *mid)
                mid--;
            if (nums[i - k] <= *mid)
                mid++;
            window.erase(window.lower_bound(nums[i - k]));
        }
        return medians;
    }
};

//上面的改写版 代码更清晰 但是速度更慢
class Solution_1 {
  public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k) {
        multiset<int> window;
        vector<double> medians;
        for (int i = 0; i < nums.size(); i++) {
            window.insert(nums[i]);
            if (window.size() >= k) {
                auto mid = next(window.begin(), k / 2);
                medians.push_back((double(*mid) + *prev(mid, 1 - k % 2)) / 2);
                window.erase(window.lower_bound(nums[i - k + 1]));
            }
        }
        return medians;
    }
};
//上面的再次的修改版
//待定 还有一点疑问

// leetcode上双队列的解法
// https://discuss.leetcode.com/topic/74724/java-solution-using-two-priorityqueues
class Solution_2 {
  public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k) {
        // priority_queue<int, vector<int>, less<int>> maxQueue;
        // priority_queue<int, vector<int>, greater<int>> minQueue;
        // int n = nums.size() - k + 1;
        // if (n <= 0)
        //     return vector<double>(1, 0);
        // vector<double> result(n, 0);
        // for (int i = 0; i <= nums.size(); i++) {
        //     if (i >= k) {
        //         result[i - k] = getMedian(maxQueue, minQueue);
        //         remove(nums[i - k], maxQueue, minQueue);
        //     }
        //     if (i < nums.size()) {
        //         add(nums[i], maxQueue, minQueue);
        //     }
        // }
        // return result;
    }

    // void add(int num, priority_queue<int> &maxHeap,
    //          priority_queue<int> &minHeap) {
    //     if (num < getMedian(maxHeap, minHeap)) {
    //         maxHeap.push(num);
    //     } else {
    //         minHeap.push(num);
    //     }
    //     if (maxHeap.size() > minHeap.size()) {
    //         minHeap.push(maxHeap.top());
    //         maxHeap.pop();
    //     }
    //     if (minHeap.size() - maxHeap.size() > 1) {
    //         maxHeap.push(minHeap.top());
    //         minHeap.pop();
    //     }
    // }

    // void remove(int num, priority_queue<int, vector<int>, less<int>>
    // &maxHeap,
    //             priority_queue<int, vector<int>, greater<int>> &minHeap) {
    //     if (num < getMedian(maxHeap, minHeap)) {
    //         maxHeap.erase(num);
    //     } else {
    //         minHeap.erase(num);
    //     }
    //     if (maxHeap.size() > minHeap.size()) {
    //         minHeap.push(maxHeap.top());
    //         maxHeap.pop();
    //     }
    //     if (minHeap.size() - maxHeap.size() > 1) {
    //         maxHeap.push(minHeap.top());
    //         minHeap.pop();
    //     }
    // }

    // double getMedian(priority_queue<int> &maxHeap,
    //                  priority_queue<int> &minHeap) {
    //     if (maxHeap.empty() && minHeap.empty())
    //         return 0;
    //     if (maxHeap.size() == minHeap.size()) {
    //         return ((double)maxHeap.top() + (double)minHeap.top()) / 2.0;
    //     } else {
    //         return (double)minHeap.top();
    //     }
    // }
};

//上面c++的实现
// https://discuss.leetcode.com/topic/74905/c-o-n-logk-using-two-std-set
class Solution_3 {
  public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k) {
        multiset<int> maxQueue, minQueue;
        int n = nums.size() - k + 1;
        if (n <= 0)
            return vector<double>(1, 0);
        vector<double> result(n, 0);
        for (int i = 0; i <= nums.size(); i++) {
            if (i >= k) {
                result[i - k] = getMedian(maxQueue, minQueue);
                remove(nums[i - k], maxQueue, minQueue);
            }
            if (i < nums.size()) {
                add(nums[i], maxQueue, minQueue);
            }
        }
        return result;
    }

    void add(int num, multiset<int> &maxHeap, multiset<int> &minHeap) {
        if (num < getMedian(maxHeap, minHeap)) {
            maxHeap.insert(num);
        } else {
            minHeap.insert(num);
        }
        if (maxHeap.size() > minHeap.size()) {
            minHeap.insert(*maxHeap.rbegin());
            maxHeap.erase(maxHeap.find(*maxHeap.rbegin()));
        }
        if (minHeap.size() - maxHeap.size() > 1) {
            maxHeap.insert(*minHeap.begin());
            minHeap.erase(minHeap.begin());
        }
    }

    void remove(int num, multiset<int> &maxHeap, multiset<int> &minHeap) {
        if (num < getMedian(maxHeap, minHeap)) {
            maxHeap.erase(maxHeap.find(num));
        } else {
            minHeap.erase(minHeap.find(num));
        }
        if (maxHeap.size() > minHeap.size()) {
            minHeap.insert(*maxHeap.rbegin());
            maxHeap.erase(maxHeap.find(*maxHeap.rbegin()));
        }
        if (minHeap.size() - maxHeap.size() > 1) {
            maxHeap.insert(*minHeap.begin());
            minHeap.erase(minHeap.begin());
        }
    }

    double getMedian(multiset<int> &maxHeap, multiset<int> &minHeap) {
        if (maxHeap.empty() && minHeap.empty())
            return 0;
        if (maxHeap.size() == minHeap.size()) {
            return ((double)(*maxHeap.rbegin()) + (double)(*minHeap.begin())) /
                   2.0;
        } else {
            return (double)*minHeap.begin();
        }
    }
};

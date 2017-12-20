#include <vector>
#include <deque>
using namespace std;
#include <set>
//第一次这么快的写出困难级别的题目，第一次提交就对了
class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> res;
        // if (nums.size() < k || k <= 0)   //不需要数据验证
        // 因为题目中已经说明都是合法的
        //     return res;
        multiset<int> directory;
        for (int i = 0; i < nums.size(); i++) {
            if (i >= k) {
                res.push_back(*directory.rbegin());
                directory.erase(directory.find(nums[i - k]));
            }
            directory.insert(nums[i]);
        }
        res.push_back(*directory.rbegin());
        return res;
    }
};

class Solution_0 {
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> res;
        multiset<int> directory;
        for (int i = 0; i < nums.size(); i++) {
            if (i >= k) {
                directory.erase(directory.find(nums[i - k]));
            }
            directory.insert(nums[i]);
            if (i >= k - 1) {
                res.push_back(*directory.rbegin());
            }
        }
        return res;
    }
};

// leetcode的答案
//用队列实现 这个方法非常的牛逼
// https://discuss.leetcode.com/topic/19055/java-o-n-solution-using-deque-with-explanation/2
// https://discuss.leetcode.com/topic/19067/clean-c-o-n-solution-using-a-deque
// Monotonic Queue
class Solution_1 {
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> windowMax;
        deque<int> dq;
        for (int i = 0; i < nums.size(); i++) {
            while (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
            if (i >= k - 1) {
                windowMax.push_back(nums[dq.front()]);
            }
        }
        return windowMax;
    }
};
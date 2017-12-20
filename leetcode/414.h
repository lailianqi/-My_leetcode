#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
//自己的解法 通过了ac 但是不符合需求 题目要求O(n)
class Solution {
  public:
    int thirdMax(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        sort(nums.begin(), nums.end(), [](int a, int b) { return a > b; });
        int m = nums.size(), counter = 1, res = nums[0];
        for (int i = 1; i < m; i++) {
            if (nums[i] != nums[i - 1]) {
                counter++;
                if (counter == 3) {
                    res = nums[i];
                    break;
                }
                res = max(res, nums[i]);
            }
        }
        return res;
    }
};
// leetcode人气最高的解法
// https://discuss.leetcode.com/topic/63715/java-neat-and-easy-understand-solution-o-n-time-o-1-space?page=1
class Solution__0 {
  public:
    int thirdMax(vector<int> &nums) {
        long long mx, sec, thr;
        mx = sec = thr = LONG_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == mx || nums[i] == sec || nums[i] <= thr) {
                continue;
            }
            if (nums[i] > mx) {
                thr = sec;
                sec = mx;
                mx = nums[i];
            } else if (nums[i] > sec) {
                thr = sec;
                sec = nums[i];
            } else if (nums[i] > thr) {
                thr = nums[i];
            }
        }
        return thr == LONG_MIN ? mx : thr;
    }
};

//使用set的解法  实际上是o(logn*n) 当时概念上可以是n 自己对leetcode的改写
// leetcode的答案
// https://discuss.leetcode.com/topic/63903/short-easy-c-using-set
class Solution_0 {
  public:
    int thirdMax(vector<int> &nums) {
        set<int> dir(nums.begin(), nums.end());
        if (dir.size() >= 3) {
            int counter = 0;
            for (auto it = dir.rbegin(); it != dir.rend(); it++) {
                if (++counter == 3) {
                    return *it;
                }
            }
        }
        return *dir.rbegin();
    }
};
// leetcode优先队列的解法
// https://discuss.leetcode.com/topic/63086/java-priorityqueue-o-n-o-1/7
// https://discuss.leetcode.com/topic/63086/java-priorityqueue-o-n-o-1/2
class Solution_1 {
  public:
    int thirdMax(vector<int> &nums) {
        priority_queue<int> pq(nums.begin(), nums.end());
        int maxNum = pq.top(), res = pq.top();
        int count = 1;
        while (!pq.empty() && count < 3) {
            int cur = pq.top();
            pq.pop();
            if (cur != res) {
                res = cur;
                count++;
            }
        }
        return count == 3 ? res : maxNum;
    }
};
void test() {
    Solution s;
    vector<int> nums = {1, 2};
    s.thirdMax(nums);
}
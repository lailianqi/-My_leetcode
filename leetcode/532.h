#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
//自己的第一种写法 成功ac 比较丑陋 纯暴力 刚开始以为过不去了 怕超时 时间是(n^2)
class Solution {
  public:
    int findPairs(vector<int> &nums, int k) {
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                for (int j = i + 1; j < nums.size(); j++) {
                    if (j == i + 1 || nums[j] != nums[j - 1]) {
                        if (nums[j] - nums[i] == k) {
                            res++;
                        } else if (nums[j] - nums[i] > k) {
                            break;
                        }
                    }
                }
            }
        }
        return res;
    }
};
//自己的第二种写法 滑动窗口的解法 成功ac 时间O(n*logn)
class Solution_0 {
  public:
    int findPairs(vector<int> &nums, int k) {
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0, j = 0; i < nums.size() && j < nums.size();) {
            if (j > i) {
                int temp = nums[j] - nums[i];
                if (temp == k &&
                    (i == 0 || (i > 0 && nums[i] != nums[i - 1]))) {
                    res++;
                    i++;
                } else if (temp < k) {
                    j++;
                } else {
                    i++;
                }
            } else {
                j++;
            }
        }
        return res;
    }
};

// LeetCode上面滑动窗口的写法 代码稍微短了一点 思想和自己的第二种解法差不多
// https://discuss.leetcode.com/topic/81745/two-pointer-approach
// https://discuss.leetcode.com/topic/81745/two-pointer-approach/2
class Solution_1 {
  public:
    int findPairs(vector<int> &nums, int k) {
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0, j = 0; i < nums.size() && j < nums.size(); i++) {
            for (j = max(j, i + 1); j < nums.size() && nums[j] - nums[i] < k;
                 j++)
                ;
            if (j < nums.size() && nums[j] - nums[i] == k)
                res++;
            while (i + 1 < nums.size() && nums[i] == nums[i + 1])
                i++;
        }
        return res;
    }
};

// 第四种写法 来自LeetCode 时间是O(n) 最牛逼的写法
// https://discuss.leetcode.com/topic/81926/c-o-n-time-with-unordered_map
class Solution_2 {
  public:
    int findPairs(vector<int> &nums, int k) {
        if (k < 0)
            return 0;
        unordered_map<int, int> m;
        for (int n : nums)
            m[n]++;
        int cnt = 0;
        for (auto p : m) {
            if ((!k && p.second > 1) || (k && m.count(p.first + k)))
                ++cnt;
        }
        return cnt;
    }
};
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;
//自己的第一次的思路，完美ac，时间的复杂度为O(n2)
class Solution {
  public:
    int lengthOfLIS(vector<int> &nums) {
        int result = 0;
        vector<int> dp(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (j == 0 || nums[j - 1] < nums[i - 1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            result = max(result, dp[i]);
        }
        return result;
    }
};

// 第二个自己的方案 上面的修改版
class Solution_ {
  public:
    int lengthOfLIS(vector<int> &nums) {
        int result = 0, m = nums.size();
        vector<int> dp(m, 1);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            result = max(result, dp[i]);
        }
        return result;
    }
};
//自己写的另外的一种方法
// Your runtime beats 67.23 % of cpp submissions.
class Solution_0 {
  public:
    int lengthOfLIS(vector<int> &nums) {
        int counter = 0;
        vector<int> paths(nums.size() + 1, INT_MAX);
        paths[counter++] = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = counter - 1; j >= 0; j--) {
                if (paths[j] < nums[i]) {
                    paths[j + 1] = min(paths[j + 1], nums[i]);
                    if (j == counter - 1)
                        counter++;
                    break;
                }
            }
        }
        return counter - 1;
    }
};
//自己写的
//上面的那种方法的改进版，时间的复杂为O(nlogn)
class Solution_1 {
  public:
    int lengthOfLIS(vector<int> &nums) {
        int counter = 0;
        vector<int> paths(nums.size() + 1, INT_MAX);
        counter++;
        for (int i = 0; i < nums.size(); i++) {
            auto it =
                lower_bound(paths.begin(), paths.begin() + counter, nums[i]);
            *(it) = min(*(it), nums[i]);
            if (it - paths.begin() == counter - 1) {
                counter++;
            }
        }
        return counter - 1;
    }
};

//下面是leetcode的答案，是上面那种方案的代码缩小版
// https://discuss.leetcode.com/topic/28696/9-lines-c-code-with-o-nlogn-complexity
class Solution_2 {
  public:
    int lengthOfLIS(vector<int> &nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            auto it = lower_bound(res.begin(), res.end(), nums[i]);
            if (it == res.end())
                res.push_back(nums[i]);
            else {
                *it = nums[i];
            }
        }
        return res.size();
    }
};
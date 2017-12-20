#include <iostream>
#include <climits>
#include <vector>
using namespace std;
//答案正确，但Time Limit Exceeded错误
class Solution {
  public:
    int jump(vector<int> &nums) {
        int m = nums.size();
        // int *dp = new int[m]();
        vector<int> dp(m, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < m; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (j + nums[j] >= i) {
                    dp[i] = min(dp[j] + 1, dp[i]);
                }
            }
        }
        return dp[m - 1];
    }
};
//答案正确，但运行时间差点超时
class Solution_0 {
  public:
    int jump(vector<int> &nums) {
        int m = nums.size();
        int i = m - 1;
        int counter = 0;
        int step = 0;
        while (i > 0) {
            step = i - 1;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[j] + j >= i) {
                    step = min(step, j);
                }
            }
            i = step;
            counter++;
        }
        return counter;
    }
};
//最快的答案
class Solution_1 {
  public:
    int jump(vector<int> &nums) {
        int n = nums.size(), step = 0, start = 0, end = 0;
        while (end < n - 1) {
            step++;
            int maxend = end + 1;
            for (int i = start; i <= end; i++) {
                if (i + nums[i] >= n - 1)
                    return step;
                maxend = max(maxend, i + nums[i]);
            }
            start = end + 1;
            end = maxend;
        }
        return step;
    }
};
//还是超时
class Solution_2 {
  public:
    int jump(vector<int> &nums) {
        int m = nums.size();
        vector<int> dp(m, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j <= i - 1; j++) {
                if (j + nums[j] >= i) {
                    if (j + nums[j] >= m - 1) {
                        return dp[j] + 1;
                    }
                    dp[i] = min(dp[j] + 1, dp[i]);
                }
            }
        }
        return dp[m - 1];
    }
};

// bfs
class Solution_3 {
  public:
    int jump(vector<int> &nums) {
        int jumps = 0, curEnd = 0, curFarthest = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            curFarthest = max(curFarthest, i + nums[i]);
            if (i == curEnd) {
                jumps++;
                curEnd = curFarthest;
                if (curEnd >= nums.size() - 1) {
                    break;
                }
            }
        }
        return jumps;
    }
};
// BFS改进版
class Solution_4 {
  public:
    int jump(vector<int> &nums) {
        int curEnd = 0, curFarthest = 0, steps = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            curFarthest = max(curFarthest, i + nums[i]);
            if (curFarthest >= nums.size() - 1) {
                return ++steps;
            }
            if (i == curEnd) {
                steps++;
                curEnd = curFarthest;
            }
        }
        return steps;
    }
};
void test() {
    Solution_4 s;
    vector<int> v = {2, 3, 0, 1, 4};
    cout << s.jump(v) << endl;
}
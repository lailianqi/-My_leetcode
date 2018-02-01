#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>
using namespace std;
// 这种解法是错的
// 这个测试用例是过不去的 [4, 0, 0, 4] -> [3, 1, 1, 3] ->[2, 2, 2, 2]
class Solution {
  public:
    int findMinMoves(vector<int> &machines) {
        int sum = accumulate(machines.begin(), machines.end(), 0),
            m = machines.size();
        if (sum % m) {
            return -1;
        }
        int averSum = sum / m;
        int step = 0;
        for (int i = 0; i < m; i++) {
            int diff = averSum - machines[i];
            step += (diff >= 0 ? diff : 0);
        }
        return step;
    }
};

// 来自LeetCode的答案
// https://discuss.leetcode.com/topic/79938/super-short-easy-java-o-n-solution?page=1
// http://blog.csdn.net/sysu_xiamengyou/article/details/70184521
class Solution_0 {
  public:
    int findMinMoves(vector<int> &machines) {
        int sum = accumulate(machines.begin(), machines.end(), 0),
            m = machines.size();
        if (sum % m) {
            return -1;
        }
        int averSum = sum / m, cnt = 0, maxStep = 0;
        for (int i = 0; i < m; i++) {
            int diff = machines[i] - averSum;
            cnt += diff;
            maxStep = max(max(maxStep, (int)abs(cnt)), diff);
        }
        return maxStep;
    }
};
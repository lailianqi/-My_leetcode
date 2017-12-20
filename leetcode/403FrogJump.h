#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
//困难级别的题目 自己独立做出来  顺利通过ac
class Solution {
  public:
    bool canCross(vector<int> &stones) {
        if (stones.size() <= 1) {
            return true;
        }
        if (stones.size() >= 2 && stones[1] != 1) {
            return false;
        }
        unordered_map<int, unordered_map<int, bool>> dir;
        return helper(stones, 1, 1, dir);
    }
    bool helper(vector<int> &stones, int start, int k,
                unordered_map<int, unordered_map<int, bool>> &dir) {
        if (start == stones.size() - 1) {
            return true;
        }
        if (dir.count(start) && dir[start].count(k)) {
            return dir[start][k];
        }
        for (int step = k - 1 == 0 ? 1 : k - 1; step <= k + 1; step++) {
            for (int i = start + 1; i < stones.size(); i++) {
                if (stones[start] + step >= stones[i])
                    if (stones[start] + step == stones[i] &&
                        helper(stones, i, step, dir)) {
                        dir[start][k] = true;
                        return true;
                    }
            }
        }
        dir[start][k] = false;
        return false;
    }
};
//上面解法的改进版 自己又改写了
class Solution_0 {
  public:
    bool canCross(vector<int> &stones) {
        unordered_map<int, unordered_map<int, bool>> dir;
        return helper(stones, 0, 0, dir);
    }
    bool helper(vector<int> &stones, int start, int k,
                unordered_map<int, unordered_map<int, bool>> &dir) {
        if (start == stones.size() - 1) {
            return true;
        }
        if (dir.count(start) && dir[start].count(k)) {
            return dir[start][k];
        }
        for (int step = max(k - 1, 1); step <= k + 1; step++) {
            for (int i = start + 1; i < stones.size(); i++) {
                if (stones[start] + step == stones[i] &&
                    helper(stones, i, step, dir)) {
                    dir[start][k] = true;
                    return true;
                }
            }
        }
        dir[start][k] = false;
        return false;
    }
};
/*
The number of stones is ≥ 2 and is < 1,100.
Each stone's position will be a non-negative integer < 231.
The first stone's position is always 0.
*/
// leetcode的答案 直接用的dp的思想
// https://discuss.leetcode.com/topic/59903/very-easy-to-understand-java-solution-with-explanations
// https://discuss.leetcode.com/topic/59903/very-easy-to-understand-java-solution-with-explanations/9?page=1
class Solution_1 {
  public:
    bool canCross(vector<int> &stones) {
        // if (stones.empty()) {
        //     return true;
        // }
        unordered_map<int, unordered_set<int>> dir;
        for (auto stone : stones) {
            dir[stone] = unordered_set<int>{};
        }
        dir[0].insert(1);
        for (int i = 0; i < stones.size(); i++) {
            for (int step : dir[stones[i]]) {
                int reach = step + stones[i];
                if (reach == stones[stones.size() - 1]) {
                    return true;
                }
                if (dir.count(reach)) {
                    for (int j = max(step - 1, 1); j <= step + 1; j++) {
                        dir[reach].insert(j);
                    }
                }
            }
        }
        return false;
    }
};

// leetcode的答案  是我原始解法的加强的版本
// https://discuss.leetcode.com/topic/59439/straight-forward-9ms-7-line-c-solution-with-explanation
class Solution_2 {
  public:
    unordered_map<int, bool> dp;
    bool canCross(vector<int> &stones, int pos = 0, int k = 0) {
        int key = pos | k << 11;
        if (dp.count(key) > 0)
            return dp[key];
        for (int i = pos + 1; i < stones.size(); i++) {
            int gap = stones[i] - stones[pos];
            if (gap < k - 1)
                continue;
            if (gap > k + 1)
                return dp[key] = false;
            if (canCross(stones, i, gap))
                return dp[key] = true;
        }
        return dp[key] = (pos == stones.size() - 1);
    }
};
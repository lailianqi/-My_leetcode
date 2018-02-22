#include <algorithm>
#include <string>
#include <vector>
using namespace std;

//这题没写出来 难而且太麻烦了 直接看的答案
class Solution {
  public:
    bool judgePoint24(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
        }
    }
    int helper(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
        }
    }
};

// LeetCode的答案 递归的写法
// https://leetcode.com/problems/24-game/discuss/107685/679.-24-Game-C++-Recursive
// https://leetcode.com/problems/24-game/discuss/107673/JAVA-Easy-to-understand.-Backtracking.
class Solution_0 {
  public:
    double elipson = pow(10.0, -5);
    vector<char> operations = {'+', '-', '*', '/'};
    bool judgePoint24(vector<int> &nums) {
        vector<double> vec;
        for (auto n : nums) {
            vec.push_back(n * 1.0);
        }
        return find24(vec);
    }
    bool find24(vector<double> vec) {
        if (vec.size() == 1) {
            return abs(vec[0] - 24.0) <= elipson;
        }
        for (int i = 0; i < vec.size(); ++i) {
            for (int j = 0; j < vec.size(); ++j) {
                if (i == j)
                    continue;
                vector<double> res;
                for (int k = 0; k < vec.size(); ++k) {
                    if (k != i && k != j)
                        res.push_back(vec[k]);
                }
                for (auto op : operations) {
                    if ((op == '+' || op == '*') && i > j)
                        continue;
                    if (op == '/' && vec[j] == 0.0)
                        continue;
                    switch (op) {
                    case '+':
                        res.push_back(vec[i] + vec[j]);
                        break;
                    case '-':
                        res.push_back(vec[i] - vec[j]);
                        break;
                    case '*':
                        res.push_back(vec[i] * vec[j]);
                        break;
                    case '/':
                        res.push_back(vec[i] / vec[j]);
                        break;
                    }
                    if (find24(res))
                        return true;
                    res.pop_back();
                }
            }
        }
        return false;
    }
};

// sp大神的解法 C++版本
// https://leetcode.com/problems/24-game/discuss/107675/Short-Python?page=1
class Solution_1 {
  public:
    bool judgePoint24(vector<int> &nums) {
        return judge24({nums.begin(), nums.end()});
    }
    bool judge24(vector<double> nums) {
        auto n = nums.size();
        if (n == 1)
            return abs(nums[0] - 24) < 1e-10;
        sort(nums.begin(), nums.end());
        do {
            vector<double> temp(nums.begin(), nums.end() - 1);
            auto a = nums[n - 1], b = nums[n - 2];
            for (auto num : {a + b, a - b, a * b, a ? b / a : 0}) {
                temp.back() = num;
                if (judge24(temp))
                    return true;
            }
        } while (next_permutation(nums.begin(), nums.end()));

        return false;
    }
};
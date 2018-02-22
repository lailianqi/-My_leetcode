#include <algorithm>
#include <cctype>
#include <numeric>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// 自己的第一种解法 成功ac
// leetcode的解法差不多
// https://leetcode.com/problems/baseball-game/discuss/107871/Straightforward-Python
// https://leetcode.com/problems/baseball-game/discuss/107860/Verbose-Java-solution-LinkedList
// https://leetcode.com/problems/baseball-game/discuss/107859/C++-Clean-Code
class Solution {
  public:
    int calPoints(vector<string> &ops) {
        vector<int> nums;
        int m = ops.size(), sum = 0;
        for (int i = 0; i < m; i++) {
            if (ops[i] == "C") {
                sum -= nums.back();
                nums.pop_back();
            } else if (ops[i] == "D") {
                sum += 2 * nums.back();
                nums.push_back(2 * nums.back());
            } else if (ops[i] == "+") {
                sum += *(nums.end() - 1) + *(nums.end() - 2);
                nums.push_back(*(nums.end() - 1) + *(nums.end() - 2));
            } else {
                sum += stoi(ops[i]);
                nums.push_back(stoi(ops[i]));
            }
        }
        return sum;
    }
};

// 上面稍微的改进版
class Solution_0 {
  public:
    int calPoints(vector<string> &ops) {
        vector<int> nums;
        int m = ops.size(), sum = 0;
        for (int i = 0; i < m; i++) {
            if (ops[i] == "C") {
                nums.pop_back();
            } else if (ops[i] == "D") {
                nums.push_back(2 * nums.back());
            } else if (ops[i] == "+") {
                nums.push_back(*(nums.end() - 1) + *(nums.end() - 2));
            } else {
                nums.push_back(stoi(ops[i]));
            }
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }
};
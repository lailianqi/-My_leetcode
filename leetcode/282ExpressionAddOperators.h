#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

//没有写出来 下面是leetcode的解法
// https://discuss.leetcode.com/topic/24523/java-standard-backtrace-ac-solutoin-short-and-clear
// https://discuss.leetcode.com/topic/35751/recommend-for-beginners-clean-c-implementation-with-detailed-explanation
class Solution {
  public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        if (num.size() == 0)
            return result;
        helper(num, target, "", 0, 0, 0, result);
        return result;
    }
    void helper(string num, int target, string path, int pos, long curValue,
                long preValue, vector<string> &res) {
        if (pos == num.size()) {
            if (curValue == target) {
                res.push_back(path);
            }
            return;
        }
        for (int i = pos; i < num.size(); i++) {
            if (num[pos] == '0' && i > pos)
                return;
            string str = num.substr(pos, i - pos + 1);
            long tempNum = stol(str);
            if (pos == 0) {
                helper(num, target, path + str, i + 1, tempNum, tempNum, res);
            } else {
                helper(num, target, path + "+" + str, i + 1, curValue + tempNum,
                       tempNum, res);
                helper(num, target, path + "-" + str, i + 1, curValue - tempNum,
                       -tempNum, res);
                helper(num, target, path + "*" + str, i + 1,
                       curValue - preValue + preValue * tempNum,
                       preValue * tempNum, res);
            }
        }
    }
};
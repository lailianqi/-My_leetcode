#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;

// 首先，这是非常好的题目，其次这题以现在的能力可以写的出来，但是最后还是没写出来
// 看了答案恍然大悟

// 自己的第一种思路 知道用递归写 可惜没写出来
// 可惜了
// 下面是自己的第一种的思路 没写出来的思路
class Solution {
  public:
    string countOfAtoms(string formula) {
        map<string, int> dir;
        for (int i = 0; i < formula.size();) {
            if (isupper(formula[i])) {
                i++;
                while (i < formula.size() && islower(formula[i])) {
                    i++;
                }
            }
        }
    }
    void helper(string formula, int index) {
        map<string, int> dir;
        int num = 0;
        for (int i = index, length = 0; i < formula.size(); i++) {
            if (isupper(formula[i])) {
                dir[formula.substr(i - length, length)] = num;
                num = 0, length = 0;
            } else if (isdigit(formula[i])) {
                num = num * 10 + (formula[i] - '0');
            } else if (islower(formula[i])) {
                length++;
            } else if (formula[i] == '(') {
            }
        }
    }
};

// 来自LeetCode的答案 和上面的思路其实差不多 但是LeetCode有人写出来了
// 写的非常的好
//  https://leetcode.com/problems/number-of-atoms/discuss/109331/C++-AC-Solution-(Map)
class Solution_0 {
  public:
    string countOfAtoms(string formula) {
        int i = 0;
        map<string, int> dir = parseElement(formula, i);
        string res;
        for (auto &p : dir) {
            res += p.first + (p.second > 1 ? to_string(p.second) : "");
        }
        return res;
    }

  private:
    map<string, int> parseElement(string &formula, int &i) {
        map<string, int> dir;
        while (i < formula.size() && formula[i] != ')') {
            if (formula[i] == '(') {
                auto m = parseElement(formula, ++i);
                for (auto &p : m) {
                    dir[p.first] += p.second;
                }
            } else {
                string atom;
                atom += formula[i++];
                while (i < formula.size() && isalpha(formula[i]) &&
                       islower(formula[i])) {
                    atom += formula[i++];
                }
                dir[atom] += parseInt(formula, i);
            }
        }
        if (i < formula.size() && formula[i] == ')') {
            int n = parseInt(formula, ++i);
            for (auto &p : dir) {
                p.second *= n;
            }
        }
        return dir;
    }
    int parseInt(string &s, int &i) {
        int n = 0;
        while (i < s.length() && isdigit(s[i]))
            n = 10 * n + s[i++] - '0';
        return n == 0 ? 1 : n;
    }
};

// 自己对上面的改写版
class Solution_1 {
  public:
    string countOfAtoms(string formula) {
        string res;
        int i = 0;
        auto m = helper(formula, i);
        for (auto &element : m) {
            res += element.first +
                   (element.second > 1 ? to_string(element.second) : "");
        }
        return res;
    }

  private:
    map<string, int> helper(string &s, int &index) {
        map<string, int> res;
        for (; index < s.size() && s[index] != ')';) {
            if (s[index] == '(') {
                auto sub = helper(s, ++index);
                for (auto &element : sub) {
                    res[element.first] += element.second;
                }
            } else {
                string atom;
                atom.push_back(s[index++]);
                while (index < s.size() && (islower(s[index]))) {
                    atom.push_back(s[index++]);
                }
                res[atom] += parseToNum(s, index);
            }
        }
        if (index < s.size() && s[index] == ')') {
            int num = parseToNum(s, ++index);
            for (auto &element : res) {
                element.second *= num;
            }
        }
        return res;
    }
    int parseToNum(string &s, int &index) {
        int res = 0;
        for (; index < s.size() && isdigit(s[index]); index++) {
            res = res * 10 + s[index] - '0';
        }
        return res == 0 ? 1 : res;
    }
};
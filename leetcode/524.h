#include <algorithm>
#include <string>
#include <vector>
using namespace std;
//一次性ac 自己的第一种解法 感觉写得非常的简洁
class Solution {
  public:
    string findLongestWord(string s, vector<string> &d) {
        sort(d.begin(), d.end(), [](string &a, string &b) {
            if (a.size() != b.size())
                return a.size() > b.size();
            return a < b;
        });
        for (int i = 0; i < d.size(); i++) {
            if (isSubstring(d[i], s)) {
                return d[i];
            }
        }
        return "";
    }
    bool isSubstring(string &a, string &b) {
        int i = 0;
        for (int j = 0; i < a.size() && j < b.size(); j++) {
            if (a[i] == b[j]) {
                i++;
            }
        }
        return i == a.size();
    }
};

// LeetCode的答案 它的第一种方案和上面的解法的思想是一样一样的
// 但是它的第二种解法没用到排序 更加的高效
// https://discuss.leetcode.com/topic/80799/short-java-solutions-sorting-dictionary-and-without-sorting
class Solution_0 {
  public:
    string findLongestWord(string s, vector<string> &d) {
        string res = "";
        for (string element : d) {
            if (isSubstring(element, s) && res.size() <= element.size()) {
                if (res.size() < element.size() || res > element) {
                    res = element;
                }
            }
        }
        return res;
    }
    bool isSubstring(string &a, string &b) {
        int i = 0;
        for (int j = 0; i < a.size() && j < b.size(); j++) {
            if (a[i] == b[j]) {
                i++;
            }
        }
        return i == a.size();
    }
};
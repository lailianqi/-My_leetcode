#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
//比较简单 一次性过
class Solution {
  public:
    int longestPalindrome(string s) {
        map<char, int> dir;
        int counter = 0;
        bool isOne = false;
        for (int i = 0; i < s.size(); i++) {
            dir[s[i]]++;
        }
        for (auto &element : dir) {
            if (element.second >= 2) {
                counter += (element.second / 2) * 2;
                element.second = element.second % 2;
            }
            if (element.second == 1 && !isOne) {
                isOne = true;
            }
        }
        return isOne ? ++counter : counter;
    }
};

// leetcode的解法 用的set
// https://discuss.leetcode.com/topic/61300/simple-hashset-solution-java
class Solution_0 {
  public:
    int longestPalindrome(string s) {
        set<char> dir;
        int counter = 0;
        for (int i = 0; i < s.size(); i++) {
            if (!dir.count(s[i])) {
                dir.insert(s[i]);
            } else {
                dir.erase(s[i]);
                counter++;
            }
        }
        return dir.empty() ? 2 * counter : 2 * counter + 1;
    }
};

// leetcode的解法  直接用的数组
// https://discuss.leetcode.com/topic/61359/java-solution-simple-and-clear-using-int-26/5

// leetcode的解法 sp大神的解法
// https://discuss.leetcode.com/topic/61338/what-are-the-odds-python-c
class Solution_1 {
  public:
    int longestPalindrome(string s) {
        int odds = 0;
        for (char c = 'A'; c <= 'z'; c++)
            odds += count(s.begin(), s.end(), c) & 1;
        return s.size() - odds + (odds > 0);
    }
};
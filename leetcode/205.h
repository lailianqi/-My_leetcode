#include <string>
#include <map>
#include <set>
using namespace std;
/*
下面的解法是错的，以下是通不过的样例
测试样例
abbaaa
cddeee
*/
class Solution {
  public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        for (int i = 1; i < s.size();) {
            if ((s[i] == s[i - 1] && t[i] == t[i - 1]) ||
                (s[i] != s[i - 1] && t[i] != t[i - 1])) {
                i++;
            } else {
                return false;
            }
        }
        return true;
    }
};
//自己的写法，用了set记录value的值
// s,t具有相同的长度，这是题目的前提，所以可以把下面的解法的开头if部分去掉
class Solution_0 {
  public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        map<char, char> directory;
        set<char> charSet;
        for (int i = 0; i < s.size(); i++) {
            if (directory.find(s[i]) != directory.end()) {
                if (t[i] != directory[s[i]]) {
                    return false;
                }
            } else {
                if (!charSet.count(t[i])) {
                    directory[s[i]] = t[i];
                    charSet.insert(t[i]);
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

//下面是leetcode的解法
// https://discuss.leetcode.com/topic/12981/my-6-lines-solution/4
class Solution_1 {
  public:
    bool isIsomorphic(string s, string t) {
        int maps1[256] = {0}, maps[256] = {0};
        int counter = 1;
        for (int i = 0; i < s.size(); i++) {
            if (maps[s[i]] != maps[t[i - 1]]) {
                return false;
            }
            if (maps[s[i]] == 0) {
                maps[s[i]] = counter;
                maps[t[i]] = counter;
                counter++;
            }
        }
        return true;
    }
};

// leetcode的python的解法
// https://discuss.leetcode.com/topic/19993/python-different-solutions-dictionary-etc
void test() {}
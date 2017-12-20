#include <string>
#include <map>
#include <vector>
#include <set>
#include <iostream>
#include <sstream>
using namespace std;
//第一种方案 感觉自己的代码有点乱
class Solution {
  public:
    bool wordPattern(string pattern, string str) {
        int left = 0, counter = 0;
        map<char, string> directory;
        set<string> sets;
        int i = 0;
        for (; i < str.size() && counter < pattern.size(); i++) {
            if (str[i] == ' ' || i == str.size() - 1) {
                string temp = str.substr(
                    left, i != str.size() - 1 ? i - left : i - left + 1);
                if (directory.find(pattern[counter]) != directory.end()) {
                    if (directory[pattern[counter]] != temp) {
                        return false;
                    }
                } else {
                    if (sets.count(temp) == 1)
                        return false;
                    directory[pattern[counter]] = temp;
                    sets.insert(temp);
                }
                counter++;
                left = i + 1;
            }
        }
        return counter == pattern.size() && i == str.size();
    }
};

// leetcode的答案
// https://discuss.leetcode.com/topic/26376/short-c-read-words-on-the-fly
// https://discuss.leetcode.com/topic/26339/8-lines-simple-java
class Solution_0 {
  public:
    bool wordPattern(string pattern, string str) {
        map<char, int> p2i;
        map<string, int> w2i;
        istringstream in(str);
        int i = 0, n = pattern.size();
        for (string word; in >> word; ++i) {
            if (i == n || p2i[pattern[i]] != w2i[word]) {
                return false;
            }
            p2i[pattern[i]] = w2i[word] = i + 1;
        }
        return i == n;
    }
};

// void test(string str) {
//     int left = 0;
//     for (int i = 0; i < str.size(); i++) {
//         if (str[i] == ' ' || i == str.size() - 1) {
//             string temp =
//                 str.substr(left, i != str.size() - 1 ? i - left : i - left +
//                 1);
//             left = i + 1;
//             cout << temp;
//         }
//     }
// }

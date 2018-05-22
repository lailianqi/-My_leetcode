#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

//  一次ac
// leetcode的解法和我的一模一样
// https://leetcode.com/problems/unique-morse-code-words/discuss/120675/C++JavaPython-Easy-and-Concise-Solution
// https://leetcode.com/problems/unique-morse-code-words/discuss/120672/C++-Straightforward
class Solution {
  public:
    int uniqueMorseRepresentations(vector<string> &words) {
        vector<string> dir = {".-",   "-...", "-.-.", "-..",  ".",    "..-.",
                              "--.",  "....", "..",   ".---", "-.-",  ".-..",
                              "--",   "-.",   "---",  ".--.", "--.-", ".-.",
                              "...",  "-",    "..-",  "...-", ".--",  "-..-",
                              "-.--", "--.."};
        int m = words.size();
        set<string> word_set;
        for (int i = 0; i < m; i++) {
            string str;
            for (int j = 0; j < words[i].size(); j++) {
                str += dir[words[i][j] - 'a'];
            }
            word_set.insert(str);
        }
        return word_set.size();
    }
};
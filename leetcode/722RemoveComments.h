#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// 这题确实没写出来 直接看的答案
// https://leetcode.com/problems/remove-comments/discuss/109216/Simple-C++-Solution-One-pass-with-explanation
// https://leetcode.com/problems/remove-comments/discuss/109197/One-pass-solution-in-Java

class Solution {
  public:
    vector<string> removeComments(vector<string> &source) {
        vector<string> ret;
        string build;
        bool block = false;
        for (string line : source) {
            for (int i = 0; i < line.size(); i++) {
                string two = line.substr(i, 2);
                if (!block) {
                    if (two == "//")
                        break;
                    else if (two == "/*")
                        block = true, i++;
                    else
                        build.push_back(line[i]);
                } else if (two == "*/") {
                    block = false, i++;
                }
            }
            if (!block && build.size()) {
                ret.push_back(build), build.clear();
            }
        }
        return ret;
    }
};
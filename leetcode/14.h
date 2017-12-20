#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
  public:
    string longestCommonPrefix(vector<string> &strs) {
        string pre = "";
        if (strs.size() == 0)
            return pre;
        int length = strs[0].size();
        int i = 1;
        while (i <= length) {
            pre = strs[0].substr(0, i);
            int j = 1;
            while (j < strs.size()) {
                if (strs[j].substr(0, i) == pre)
                    j++;
                else
                    return strs[0].substr(0, i - 1);
            }
            i++;
        }
        return strs[0].substr(0, i - 1);
    }
};

class Solution_0 {
  public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0)
            return "";
        string pre = strs[0];
        for (int i = 0; i < strs.size(); i++) {
            while (strs[i].find(pre) != 0) {
                pre = pre.substr(0, pre.size() - 1);
            }
        }
        return pre;
    }
};
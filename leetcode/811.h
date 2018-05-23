#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 自己的第一种解法 一次ac
// LeetCode的解法和我的差不多
// https://leetcode.com/problems/subdomain-visit-count/discuss/121738/C++JavaPython-Solution
// https://leetcode.com/problems/subdomain-visit-count/discuss/121726/Java-solutionvery-easy-to-understand!
// https://leetcode.com/problems/subdomain-visit-count/discuss/129879/C++-O(sum-of-lengths-of-strings)-simple-Solution

class Solution {
  public:
    vector<string> subdomainVisits(vector<string> &cpdomains) {
        int m = cpdomains.size();
        unordered_map<string, int> dir;
        for (int i = 0; i < m; i++) {
            int n = cpdomains[i].size(),
                blank = cpdomains[i].find_first_of(' ');
            int num = stoi(cpdomains[i].substr(0, blank));
            for (int j = blank; j < n; j++) {
                if (cpdomains[i][j] == '.' || cpdomains[i][j] == ' ') {
                    dir[cpdomains[i].substr(j + 1)] += num;
                }
            }
        }
        vector<string> res;
        for (auto &e : dir) {
            string str;
            str += to_string(e.second) + " " + e.first;
            res.push_back(str);
        }
        return res;
    }
};
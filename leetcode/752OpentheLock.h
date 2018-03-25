#include <algorithm>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

// 这题没写出来 直接看的LeetCode的答案 其实类似的题目应该用BFS
// 这里的写法是错的 我的第一种思路的解法
class Solution {
  public:
    int openLock(vector<string> &deadends, string target) {
        unordered_set<string> dir(deadends.begin(), deadends.end());
        string s = "0000";
        helper(s, dir, target, 0);
        return res;
    }
    void helper(string &s, unordered_set<string> &dir, string &target,
                int cur) {
        if (res < cur) {
            return;
        }
        if (s == target && res > cur) {
            res = min(res, cur);
            return;
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] < '9') {
                s[i]++;
                if (dir.count(s) == 0) {
                    helper(s, dir, target, cur + 1);
                }
                s[i]--;
            }
        }
    }

  private:
    int res = INT_MAX;
};

// 来自LeetCode的答案
// https://leetcode.com/problems/open-the-lock/discuss/110230/BFS-solution-C++
// https://leetcode.com/problems/open-the-lock/discuss/110247/JavaC++-Clean-Code
class Solution_0 {
  public:
    int openLock(vector<string> &deadends, string target) {
        unordered_set<string> dir(deadends.begin(), deadends.end()), visited;
        if (dir.count("0000")) {
            return -1;
        }
        if (target == "0000") {
            return 0;
        }
        int res = 0;
        queue<string> q;
        q.push("0000");
        while (!q.empty()) {
            res++;
            int m = q.size();
            for (int i = 0; i < m; i++) {
                string cur = q.front();
                q.pop();
                for (int j = 0; j < 4; j++) {
                    for (int dif = 1; dif <= 9; dif += 8) {
                        string s = cur;
                        s[j] = (s[j] - '0' + dif) % 10 + '0';
                        if (s == target)
                            return res;
                        if (!dir.count(s) && !visited.count(s))
                            q.push(s);
                        visited.insert(s);
                    }
                }
            }
        }
        return -1;
    }
};

// 还要一种解法 双向BFS Bidirectional BFS
// https://leetcode.com/problems/open-the-lock/discuss/110237/Regular-java-BFS-solution-and-2-end-BFS-solution-with-improvement
// https://leetcode.com/problems/open-the-lock/discuss/110230/BFS-solution-C++

class Solution_1 {
  public:
    int openLock(vector<string> &deadends, string target) {
        unordered_set<string> dir(deadends.begin(), deadends.end()), begin, end,
            pass;
        if (dir.count("0000") || dir.count(target)) {
            return -1;
        }
        int res = 0;
        begin.insert("0000"), end.insert(target);
        while (!begin.empty() && !end.empty()) {
            if (begin.size() > end.size()) {
                swap(begin, end);
            }
            pass.clear();
            for (const string &element : begin) {
                if (end.count(element)) {
                    return res;
                }
                if (dir.count(element)) {
                    continue;
                }
                dir.insert(element);
                for (int j = 0; j < 4; j++) {
                    for (int dif = 1; dif <= 9; dif += 8) {
                        string s = element;
                        s[j] = (s[j] - '0' + dif) % 10 + '0';
                        if (dir.count(s) == 0) {
                            pass.insert(s);
                        }
                    }
                }
            }
            swap(begin, pass);
            res++;
        }
        return -1;
    }
};

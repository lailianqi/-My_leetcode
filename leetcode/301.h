#include <vector>
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;
/*
"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]
*/
// http://lib.csdn.net/article/datastructure/18481
// https://discuss.leetcode.com/topic/34875/easy-short-concise-and-fast-java-dfs-3-ms-solution/2
// https://discuss.leetcode.com/topic/28827/share-my-java-bfs-solution/2
// https://discuss.leetcode.com/topic/34875/easy-short-concise-and-fast-java-dfs-3-ms-solution/24?page=2
// http://blog.csdn.net/wyh476901857/article/details/70115456
/*
    0 1 2 3 4 5 6
    ( ) ( ) ) ( )
*/
//根本写不出来
//这个题目非常的难，已经是暂时瘫痪的状态
class Solution {
  public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        helper(s, result, 0, 0, string{'(', ')'});
        return result;
    }
    void helper(string s, vector<string> &result, int curPos, int last,
                string str) {
        for (int i = curPos, cnt = 0; i < s.size(); i++) {
            if (s[i] == str[0]) {
                cnt++;
            } else if (s[i] == str[1]) {
                cnt--;
            }
            if (cnt >= 0)
                continue;
            for (int j = last; j <= i; j++) {
                if (s[j] == str[1] && (j == last || s[j - 1] != str[1])) {
                    helper(s.substr(0, j) + s.substr(j + 1), result, i, j, str);
                }
            }
            return;
        }
        reverse(s.begin(), s.end());
        if (str[0] == '(')
            helper(s, result, 0, 0, string{')', '('});
        else
            result.push_back(s);
    }
};

// BFS的解法
// https://discuss.leetcode.com/topic/28827/share-my-java-bfs-solution/2
// https://discuss.leetcode.com/topic/28827/share-my-java-bfs-solution/37?page=2
// jianchao-li-fighter的解释
class Solution_0 {
  public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        if (s == "") {
            result.push_back(s);
            return result;
        }
        unordered_set<string> visited;
        /*** use the deque to do the BFS ***/
        deque<string> queue;
        queue.push_back(s);
        visited.insert(s);
        bool found = false;
        while (!queue.empty()) {
            string temp = queue.front();
            queue.pop_front();
            if (isValid(temp)) {
                result.push_back(temp);
                found = true;
            }
            if (found)
                continue;
            for (int i = 0; i < temp.size(); i++) {
                if (temp[i] != '(' && temp[i] != ')')
                    continue;
                string str = temp.substr(0, i) + temp.substr(i + 1);
                if (visited.find(str) == visited.end()) {
                    queue.push_back(str);
                    visited.insert(str);
                }
            }
        }
        return result;
    }
    bool isValid(string s) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c == '(')
                count++;
            if (c == ')' && count-- == 0)
                return false;
        }
        return count == 0;
    }
};

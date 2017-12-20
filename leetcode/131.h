#include <vector>
#include <string>
using namespace std;

// Your runtime beats 72.18 % of cpp submissions.
//自己的写法 也就是回溯加DFS
class Solution {
  public:
    vector<vector<string>> ans;
    vector<vector<string>> partition(string s) {
        vector<string> an;
        partition(s, an, 0, s.size() - 1);
        return ans;
    }
    void partition(string &s, vector<string> &an, int begin, int end) {
        if (begin > end) {
            ans.push_back(an);
            return;
        }
        for (int i = begin; i <= end; i++) {
            if (judgePalindromic(s, begin, i)) {
                an.push_back(s.substr(begin, i - begin + 1));
                partition(s, an, i + 1, end);
                an.erase(an.begin() + an.size() - 1);
            }
        }
    }
    bool judgePalindromic(const string &s, int i, int j) {
        for (; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
};
// leetcode的答案 关于dp的
// https://discuss.leetcode.com/topic/2884/my-java-dp-only-solution-without-recursion-o-n-2/21?page=2
class Solution_0 {
  public:
    vector<vector<string>> partition(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        vector<vector<vector<string>>> answers(s.size() + 1);
        answers[0] = vector<vector<string>>(1, vector<string>());
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j <= i; j++) {
                if (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1])) {
                    dp[j][i] = true;
                    for (auto arr : answers[j]) {
                        arr.push_back(s.substr(j, i - j + 1));
                        answers[i + 1].push_back(arr);
                    }
                }
            }
        }
        return answers[s.size()];
    }
};

// Python的解决方案
// https://discuss.leetcode.com/topic/19370/1-liner-python-ruby
/*
def partition(self, s):
return [[s[:i]] + rest
        for i in xrange(1, len(s)+1)
        if s[:i] == s[i-1::-1]
        for rest in self.partition(s[i:])] or [[]]
        */
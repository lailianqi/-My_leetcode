#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
// Time Limit Exceeded
//思路错了 不应该用递归来写，肯定是超时的
class Solution {
  public:
    bool wordBreak(string s, vector<string> &wordDict) {
        return wordBreak(s, "", wordDict);
    }
    bool wordBreak(string &s, string target, vector<string> &wordDict) {
        if (s == target) {
            return true;
        }
        if (target.size() > s.size()) {
            return false;
        }
        for (int i = 0; i < wordDict.size(); i++) {
            if (wordBreak(s, target + wordDict[i], wordDict)) {
                return true;
            }
        }
        return false;
    }
};

//下面是dp的解法
// http://blog.csdn.net/linhuanmars/article/details/22358863/
class Solution_0 {
  public:
    bool wordBreak(string s, vector<string> &wordDict) {
        int m = s.size();
        vector<bool> dp(m + 1, false);
        set<string> directoty(wordDict.begin(), wordDict.end());
        dp[0] = true;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j <= i; j++) {
                if (dp[j] && directoty.find(s.substr(j, i - j + 1)) != directoty.end()) {
                    dp[i + 1] = true;
                    break;
                }
            }
        }
        return dp[m];
    }
};

void test() {
    Solution_0 s;
    vector<string> wordDict = {"leet", "code"};
    s.wordBreak("leetcode", wordDict);
}
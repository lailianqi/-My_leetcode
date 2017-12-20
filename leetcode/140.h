#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
// Memory Limit Exceeded
class Solution {
  public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        int m = s.size();
        vector<bool> dp(m + 1, false);
        set<string> directoty(wordDict.begin(), wordDict.end());
        dp[0] = true;
        vector<vector<string>> results(m + 1, vector<string>());
        results[0] = {""};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j <= i; j++) {
                string temp = s.substr(j, i - j + 1);
                if (dp[j] && directoty.find(temp) != directoty.end()) {
                    dp[i + 1] = true;
                    for (auto element : results[j]) {
                        results[i + 1].push_back(
                            element == "" ? temp : element + " " + temp);
                    }
                }
            }
        }
        return results[m];
    }
};
// https://discuss.leetcode.com/topic/8178/slightly-modified-dp-java-solution
// https://discuss.leetcode.com/topic/12997/11ms-c-solution-concise
// https://discuss.leetcode.com/topic/27855/my-concise-java-solution-based-on-memorized-dfs
class Solution_0 {
  public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        set<string> directoty(wordDict.begin(), wordDict.end());
        map<string, vector<string>> Maps;
        return wordBreak(s, directoty, Maps);
    }
    vector<string> wordBreak(string s, set<string> &wordDict,
                             map<string, vector<string>> &Maps) {
        if (Maps.count(s)) {
            return Maps[s];
        }
        vector<string> res;
        if (wordDict.count(s)) { // a whole string is a word
            res.push_back(s);
        }
        for (int i = 0; i < s.size() - 1; i++) {
            string word = s.substr(0, i + 1);
            if (wordDict.count(word)) {
                string rem = s.substr(word.size());
                vector<string> sublist = wordBreak(rem, wordDict, Maps);
                for (string sub : sublist) {
                    res.push_back(word + (sub.empty() ? "" : " ") + sub);
                }
            }
        }
        Maps[s] = res;
        return res;
    }
};

//下面是dp的解法,还未修改。
// https://discuss.leetcode.com/topic/18089/java-dp-solution/6
class Solution_1 {
  public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        int m = s.size();
        vector<bool> dp(m + 1, false);
        set<string> directoty(wordDict.begin(), wordDict.end());
        if (!wordBreak(s, directoty, dp))
            return vector<string>();
        vector<vector<string>> results(m + 1, vector<string>());
        results[0] = {""};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j <= i; j++) {
                string temp = s.substr(j, i - j + 1);
                if (dp[j] && directoty.find(temp) != directoty.end()) {
                    for (auto element : results[j]) {
                        results[i + 1].push_back(
                            element == "" ? temp : element + " " + temp);
                    }
                }
            }
        }
        return results[m];
    }
    bool wordBreak(string s, set<string> &directoty, vector<bool> &dp) {
        int m = s.size();
        dp[0] = true;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j <= i; j++) {
                if (dp[j] &&
                    directoty.find(s.substr(j, i - j + 1)) != directoty.end()) {
                    dp[i + 1] = true;
                    break;
                }
            }
        }
        return dp[m];
    }
};
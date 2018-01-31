#include <algorithm>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
// 参照139题可以写出
// 用set时 时间效率一般 改为unordered_set 后效率大幅提升
// LeetCode上面类似的答案
// https://discuss.leetcode.com/topic/72113/java-dp-solution
class Solution {
  public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
        vector<string> res;
        unordered_set<string> dict;
        sort(words.begin(), words.end(),
             [](string &a, string &b) { return a.size() < b.size(); });
        for (int i = 0; i < words.size(); i++) {
            if (formWord(words[i], dict)) {
                res.push_back(words[i]);
            }
            dict.insert(words[i]);
        }
        return res;
    }
    bool formWord(string &s, unordered_set<string> &dict) {
        if (s.empty()) {
            return false;
        }
        int m = s.size();
        vector<bool> dp(m + 1, false);
        dp[0] = true;
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < i; j++) {
                // s本身不在words里面 所以可以用dp来写
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[m];
    }
};

//另外的一种方法 Trie + DFS solution
//下面是c++的版本 代码和Java一样 但是就是过不去
// https://discuss.leetcode.com/topic/75089/102ms-java-trie-dfs-solution-with-explanation-easy-to-understand
class Solution_0 {
  private:
    class TrieNode {
      public:
        vector<TrieNode *> sons;
        bool isEnd;

      public:
        TrieNode() { sons = vector<TrieNode *>(26, NULL); }
    };

  public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
        TrieNode *root = new TrieNode();
        vector<string> res;
        for (string word : words) { // construct Trie tree
            if (word.size() == 0) {
                continue;
            }
            addWord(word, root);
        }
        for (string word : words) {
            if (word.size() == 0)
                continue;
            if (testWord(word, 0, root, 0)) {
                res.push_back(word);
            }
        }
        return res;
    }
    bool testWord(string &s, int start, TrieNode *root, int counter) {
        TrieNode *cur = root;
        int m = s.size();
        for (int i = start; i < s.size(); i++) {
            if (cur->sons[s[i] - 'a'] == NULL) {
                return false;
            }
            if (cur->sons[s[i] - 'a']->isEnd) {
                if (i == m - 1) { // no next word, so test count to get result.
                    return counter >= 1;
                }
                if (testWord(s, i + 1, root, counter + 1)) {
                    return true;
                }
            }
            cur = cur->sons[s[i] - 'a'];
        }
        return false;
    }
    void addWord(string &str, TrieNode *root) {
        TrieNode *cur = root;
        for (int i = 0; i < str.size(); i++) {
            if (cur->sons[str[i] - 'a'] == NULL) {
                cur->sons[str[i] - 'a'] = new TrieNode();
            }
            cur = cur->sons[str[i] - 'a'];
        }
        cur->isEnd = true;
    }
};

//上面的改写版
class Solution_1 {
  private:
    class TrieNode {
      public:
        vector<TrieNode *> sons;
        bool isEnd;

      public:
        TrieNode() { sons = vector<TrieNode *>(26, NULL); }
    };

  public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
        TrieNode *root = new TrieNode();
        vector<string> res;
        for (string word : words) { // construct Trie tree
            if (word.size() == 0) {
                continue;
            }
            addWord(word, root);
        }
        for (string word : words) {
            if (word.size() == 0)
                continue;
            if (testWord(word, 0, root)) {
                res.push_back(word);
            }
        }
        return res;
    }
    bool testWord(string &s, int start, TrieNode *root) {
        if (start >= s.size()) {
            return true;
        }
        TrieNode *cur = root;
        int m = s.size();
        for (int i = start; i < s.size(); i++) {
            if (cur->sons[s[i] - 'a'] == NULL) {
                return false;
            }
            if (cur->sons[s[i] - 'a']->isEnd &&
                (!(i == s.size() - 1 && start == 0)) &&
                testWord(s, i + 1, root)) {
                return true;
            }
            cur = cur->sons[s[i] - 'a'];
        }
        return false;
    }
    void addWord(string &str, TrieNode *root) {
        TrieNode *cur = root;
        for (int i = 0; i < str.size(); i++) {
            if (cur->sons[str[i] - 'a'] == NULL) {
                cur->sons[str[i] - 'a'] = new TrieNode();
            }
            cur = cur->sons[str[i] - 'a'];
        }
        cur->isEnd = true;
    }
};
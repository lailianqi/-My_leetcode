#include <algorithm>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
class Trie {
    class TrieNode {
      public:
        TrieNode *next[26] = {NULL};
        bool is_word;
        // Initialize your data structure here.
        TrieNode(bool b = false) { is_word = b; }
    };

  public:
    TrieNode *root;
    /** Initialize your data structure here. */
    Trie() { root = new TrieNode(); }
    void buildTrie(vector<string> &words) {
        for (int i = 0; i < words.size(); i++) {
            insert(words[i]);
        }
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *curr = root;
        for (auto c : word) {
            if (curr->next[c - 'a'] == NULL) {
                curr->next[c - 'a'] = new TrieNode();
            }
            curr = curr->next[c - 'a'];
        }
        curr->is_word = true;
    }

    int find(string word) {
        int res = 0;
        TrieNode *curr = root;
        for (int i = 0; i < word.size() && curr != NULL; i++) {
            curr = curr->next[word[i] - 'a'];
            if (curr == NULL) {
                break;
            }
            res++;
            if (curr->is_word) {
                return res;
            }
        }
        return -1;
    }
};

// 自己对LeetCode答案的改写版
// 自己第一次没写出来 只想到了最naive的方法 也就是第二种方法
// https://leetcode.com/problems/replace-words/discuss/105795/Simple-Java-8-and-Trie-based-solution
// https://leetcode.com/problems/replace-words/discuss/105767/Java-SimpleClassical-Trie-questionsolution-(Beat-96)
// https://leetcode.com/problems/replace-words/discuss/105794/C++-trietree-solution-easy-to-read-and-understand
class Solution {
  public:
    string replaceWords(vector<string> &dict, string sentence) {
        stringstream ss(sentence);
        string token;
        string res = "";
        Trie tree;
        tree.buildTrie(dict);
        while (getline(ss, token, ' ')) {
            int length = tree.find(token);
            if (length != -1) {
                res += token.substr(0, length);
            } else {
                res += token;
            }
            res += " ";
        }
        return res.substr(0, res.size() - 1);
    }
};

// LeetCode 第二种解法 直接用的hash 估计效率不太高
// https://leetcode.com/problems/replace-words/discuss/105757/Java-solution-12-lines-HashSet
class Solution_0 {
  public:
    string replaceWords(vector<string> &dict, string sentence) {
        stringstream ss(sentence);
        string token, res;
        unordered_set<string> dir(dict.begin(), dict.end());
        while (getline(ss, token, ' ')) {
            string prefix;
            for (int i = 1; i <= token.size(); i++) {
                prefix = token.substr(0, i);
                if (dir.count(prefix))
                    break;
            }
            res += " " + prefix;
        }
        return res.substr(1);
    }
};
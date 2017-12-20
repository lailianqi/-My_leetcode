#include <vector>
#include <string>
#include <set>
using namespace std;
//这种解法毫无疑问会超时,所以没有通过leetcode
class Solution {
  public:
    vector<string> findWords(vector<vector<char>> &board,
                             vector<string> &words) {
        set<string> directory(words.begin(), words.end());
        vector<string> wordsCopy(directory.begin(), directory.end());
        vector<string> res;
        for (int i = 0; i < wordsCopy.size(); i++) {
            if (exist(board, wordsCopy[i])) {
                res.push_back(wordsCopy[i]);
            }
        }
        return res;
    }
    bool exist(vector<vector<char>> &board, string word) {
        if (board.size() == 0)
            return false;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (help(board, i, j, 0, word))
                    return true;
            }
        }
        return false;
    }

    bool help(vector<vector<char>> &board, int i, int j, int len, string word) {
        if (len == word.size())
            return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
            return false;
        if (board[i][j] != word[len] || board[i][j] == '*')
            return false;
        char ch = board[i][j];
        board[i][j] = '*';
        bool result = help(board, i + 1, j, len + 1, word) ||
                      help(board, i - 1, j, len + 1, word) ||
                      help(board, i, j + 1, len + 1, word) ||
                      help(board, i, j - 1, len + 1, word);
        board[i][j] = ch;
        return result;
    }
};

class TrieNode {
  public:
    TrieNode *next[26] = {NULL};
    bool is_word;
    TrieNode(bool b = false) { is_word = b; }
};
// leetcode的解法
// https://discuss.leetcode.com/topic/20210/my-ac-very-clean-c-code
class Solution_0 {
  public:
    vector<string> findWords(vector<vector<char>> &board,
                             vector<string> &words) {
        vector<string> res;
        TrieNode *root = buildTrie(words);
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                helper(board, i, j, "", root, res);
            }
        }
        return res;
    }
    TrieNode *buildTrie(vector<string> &words) {
        TrieNode *root = new TrieNode();
        for (int i = 0; i < words.size(); i++) {
            addWord(words[i], root);
        }
        return root;
    }
    void addWord(string &word, TrieNode *root) {
        TrieNode *curr = root;
        for (auto c : word) {
            if (curr->next[c - 'a'] == NULL) {
                curr->next[c - 'a'] = new TrieNode();
            }
            curr = curr->next[c - 'a'];
        }
        curr->is_word = true;
    }
    void helper(vector<vector<char>> &board, int i, int j, string word,
                TrieNode *root, vector<string> &res) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
            return;
        char ch = board[i][j];
        if (ch == '*' || root->next[ch - 'a'] == NULL)
            return;
        root = root->next[ch - 'a'];
        word = word + ch;
        if (root->is_word) {
            res.push_back(word);
            root->is_word = false;
        }
        board[i][j] = '*';
        helper(board, i + 1, j, word, root, res);
        helper(board, i - 1, j, word, root, res);
        helper(board, i, j + 1, word, root, res);
        helper(board, i, j - 1, word, root, res);
        board[i][j] = ch;
    }
};

void test() {
    Solution_0 s;
    vector<vector<char>> boards = {{'o', 'a', 'a', 'n'},
                                   {'e', 't', 'a', 'e'},
                                   {'i', 'h', 'k', 'r'},
                                   {'i', 'f', 'l', 'v'}};
    vector<string> words = {"oath", "pea", "eat", "rain"};
    s.findWords(boards, words);
}
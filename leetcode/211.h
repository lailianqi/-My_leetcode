#include <vector>
#include <string>
#include <queue>
#include <iostream>
using namespace std;
class TrieNode {
  public:
    TrieNode *next[26] = {NULL};
    bool is_word;
    TrieNode(bool b = false) { is_word = b; }
};
//自己的写法，顺利通过leetcode Your runtime beats 72.26 % of cpp submissions.
class WordDictionary {
  public:
    /** Initialize your data structure here. */
    WordDictionary() { root = new TrieNode(); }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *curr = root;
        for (auto c : word) {
            if (curr->next[c - 'a'] == NULL) {
                curr->next[c - 'a'] = new TrieNode();
            }
            curr = curr->next[c - 'a'];
        }
        curr->is_word = true;
    }

    /** Returns if the word is in the data structure. A word could contain the
     * dot character '.' to represent any one letter. */
    bool search(string word) {
        queue<TrieNode *> charQueue;
        charQueue.push(root);
        int i = 0;
        while (!charQueue.empty() && i < word.size()) {
            int size = charQueue.size();
            for (int j = 0; j < size; j++) {
                TrieNode *current = charQueue.front();
                charQueue.pop();
                if (word[i] != '.') {
                    if (current->next[word[i] - 'a']) {
                        charQueue.push(current->next[word[i] - 'a']);
                    }
                } else {
                    for (int i = 0; i < 26; i++) {
                        if (current->next[i]) {
                            charQueue.push(current->next[i]);
                        }
                    }
                }
            }
            i++;
        }
        while (!charQueue.empty() && i == word.size()) {
            TrieNode *current = charQueue.front();
            if (current->is_word)
                return true;
            charQueue.pop();
        }
        return false;
    }

  private:
    TrieNode *root;
};
// leetcode上面的解法，search部分采用递归的写法，而我的解法采用的是队列遍历
// https://discuss.leetcode.com/topic/14030/my-simple-and-clean-java-code/5
class WordDictionary_0 {
  public:
    /** Initialize your data structure here. */
    WordDictionary_0() { root = new TrieNode(); }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *curr = root;
        for (auto c : word) {
            if (curr->next[c - 'a'] == NULL) {
                curr->next[c - 'a'] = new TrieNode();
            }
            curr = curr->next[c - 'a'];
        }
        curr->is_word = true;
    }

    /** Returns if the word is in the data structure. A word could contain the
     * dot character '.' to represent any one letter. */
    bool search(string word) { return match(word, 0, root); }
    bool match(const string &word, int k, TrieNode *root) {
        if (k == word.size()) {
            return root->is_word;
        }
        if (word[k] == '.') {
            for (int i = 0; i < 26; i++) {
                if (root->next[i] && match(word, k + 1, root->next[i])) {
                    return true;
                }
            }
        } else {
            return root->next[word[k] - 'a'] &&
                   match(word, k + 1, root->next[word[k] - 'a']);
        }
        return false;
    }

  private:
    TrieNode *root;
};

void test() {
    WordDictionary s;
    s.addWord("bad");
    s.addWord("dad");
    s.addWord("mad");
    if (s.search("pad")) {
        cout << "true" << endl;
    }
    if (s.search("bad")) {
        cout << "true" << endl;
    }
    if (s.search(".ad")) {
        cout << "true" << endl;
    }
    if (s.search("b..")) {
        cout << "true" << endl;
    }
}
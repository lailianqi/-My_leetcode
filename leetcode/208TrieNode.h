#include <string>
using namespace std;
// leetcode的答案
// https://discuss.leetcode.com/topic/13463/maybe-the-code-is-not-too-much-by-using-next-26-c
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

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p = find(word);
        return p != NULL && p->is_word;
    }

    /** Returns if there is any word in the trie that starts with the given
     * prefix. */
    bool startsWith(string prefix) {
        TrieNode *p = find(prefix);
        return p != NULL;
    }

  private:
    TrieNode *find(string word) {
        TrieNode *curr = root;
        for (int i = 0; i < word.size() && curr != NULL; i++)
            curr = curr->next[word[i] - 'a'];
        return curr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

class Trie_0 {
  public:
    class TrieNode {
      public:
        TrieNode *next[26] = {NULL};
        char val;
        bool is_word;
        // Initialize your data structure here.
        TrieNode(char val = ' ', bool is_word = false)
            : val(val), is_word(is_word) {}
    };
    /** Initialize your data structure here. */
    Trie_0() { root = new TrieNode(' '); }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *curr = root;
        for (auto c : word) {
            if (curr->next[c - 'a'] == NULL) {
                curr->next[c - 'a'] = new TrieNode(c);
            }
            curr = curr->next[c - 'a'];
        }
        curr->is_word = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p = find(word);
        return p != NULL && p->is_word;
    }

    /** Returns if there is any word in the trie that starts with the given
     * prefix. */
    bool startsWith(string prefix) { return find(prefix) != NULL; }
    TrieNode *find(string word) {
        TrieNode *curr = root;
        for (int i = 0; i < word.size() && curr != NULL; i++)
            curr = curr->next[word[i] - 'a'];
        return curr;
    }
  private:
    TrieNode *root;
};
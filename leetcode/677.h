#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// 第一种方案 成功ac 但是简陋
class MapSum {
  public:
    /** Initialize your data structure here. */
    MapSum() {}

    void insert(string key, int val) { dir[key] = val; }

    int sum(string prefix) {
        int sum = 0;
        for (auto element : dir) {
            if (element.first.find(prefix) == 0) {
                sum += element.second;
            }
        }
        return sum;
    }

  private:
    unordered_map<string, int> dir;
};

// https://leetcode.com/problems/map-sum-pairs/discuss/107513/Java-solution-Trie
class MapSum_0 {
  private:
    class TrieNode {
      public:
        TrieNode *next[26] = {NULL};
        bool is_word;
        int val;
        // Initialize your data structure here.
        TrieNode(bool b = false, int val = 0) {
            is_word = b;
            this->val = val;
        }
    };
    TrieNode *root;
    unordered_map<string, int> dir;

  public:
    /** Initialize your data structure here. */
    MapSum_0() { root = new TrieNode(); }

    void insert(string key, int val) {
        TrieNode *curr = root;
        for (auto c : key) {
            if (curr->next[c - 'a'] == NULL) {
                curr->next[c - 'a'] = new TrieNode();
            }
            curr = curr->next[c - 'a'];
        }
        curr->is_word = true;
        curr->val = val;
    }

    int sum(string prefix) {
        TrieNode *curr = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (curr->next[prefix[i] - 'a']) {
                curr = curr->next[prefix[i] - 'a'];
            } else {
                return 0;
            }
        }
        return helper(curr);
    }
    int helper(TrieNode *t) {
        int res = 0;
        if (t) {
            res += t->val;
            for (int i = 0; i < 26; i++) {
                res += helper(t->next[i]);
            }
        }
        return res;
    }
};
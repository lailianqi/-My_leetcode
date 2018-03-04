#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
// 这破题居然一时半会没想明白 真是操蛋  直接看的LeetCode的答案
// https://leetcode.com/problems/longest-word-in-dictionary/discuss/109114/JavaC++-Clean-Code
class Solution {
  public:
    string longestWord(vector<string> &words) {
        sort(words.begin(), words.end());
        unordered_set<string> dir;
        string res;
        for (int i = 0; i < words.size(); i++) {
            if (words[i].size() == 1 ||
                dir.count(words[i].substr(0, words[i].size() - 1))) {
                res = words[i].size() > res.size() ? words[i] : res;
                dir.insert(words[i]);
            }
        }
        return res;
    }
};

// python 的写法 来自LeetCode的答案
// https://leetcode.com/problems/longest-word-in-dictionary/discuss/109140/Simple-short-7-lines-python-solution-using-sorting-and-set
/*
def longestWord(self, words):
        words, resword, res = sorted(words), '', set()
        for word in words:
            if len(word) == 1 or word[:-1] in res:
                res.add(word)
                resword = word if resword == '' else word if len(word) > len(resword) else resword
        return resword


sp大神的解法
def longestWord(self, words):
    resword, res = '', {''}
    for word in sorted(words):
        if word[:-1] in res:
            res.add(word)
            resword = max(resword, word, key=len)
    return resword
Another version:

def longestWord(self, words):
    valids = {''}
    for word in sorted(words):
        if word[:-1] in valids:
            valids.add(word)
    return max(sorted(valids), key=len)
*/
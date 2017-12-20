#include <string>
#include <deque>
#include <algorithm>
#include <vector>
using namespace std;
// https://segmentfault.com/a/1190000004188227
// http://www.cnblogs.com/7z7chn/p/6341453.html
// https://discuss.leetcode.com/topic/31404/a-short-o-n-recursive-greedy-solution?page=1
/*
Example:
Given "bcabc"
Return "abc"
Given "cbacdcbc"
Return "acdb"
*/
/*
题目分析：消除掉重复字符串后剩下的字符串要按照字典排序。我们这样思考，对于每个字符，至少得剩下一个。首先，我们遍历字符串，
记录每个字符出现的次数，然后，我们继续从头遍历字符串，每次遍历到一个字符的时候，我们需要把该字符次数减一，
当减到只剩下1的时候，表示最多只能删除到当前，因为是按照字典排序，我们需要找到到当前位置的最小字符以及其位置，
那个该位置之前的字符可以被删除，最小字符也可以被删除，提取最小字符，递归查找新串。
*/
class Solution {
  public:
    string removeDuplicateLetters(string s) {
        if (s.empty()) {
            return s;
        }
        vector<int> cnt(26, 0);
        for (int i = 0; i < s.size(); i++) {
            cnt[s[i] - 'a']++;
        }
        int pos = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] < s[pos]) {
                pos = i;
            }
            if (--cnt[s[i] - 'a'] == 0) {
                break;
            }
        }
        string str = s.substr(pos + 1);
        str.erase(remove(str.begin(), str.end(), s[pos]), str.end());
        return s[pos] + removeDuplicateLetters(str);
    }
};
// https://discuss.leetcode.com/topic/32259/java-solution-using-stack-with-comments
class Solution_0 {
  public:
    string removeDuplicateLetters(string s) {
        vector<int> cnt(26, 0);
        vector<bool> visit(26, false);
        deque<char> characterQueue;
        for (int i = 0; i < s.size(); i++) {
            cnt[s[i] - 'a']++;
        }
        int index = 0;
        for (int i = 0; i < s.size(); i++) {
            index = s[i] - 'a';
            cnt[index]--;
            if (!visit[index]) {
                while (!characterQueue.empty() &&
                       characterQueue.back() > s[i] &&
                       cnt[characterQueue.back() - 'a'] > 0) {
                    visit[characterQueue.back() - 'a'] = false;
                    characterQueue.pop_back();
                }
                characterQueue.push_back(s[i]);
                visit[index] = true;
            }
        }
        string result;
        while (!characterQueue.empty()) {
            result += characterQueue.front();
            characterQueue.pop_front();
        }
        return result;
    }
};

//另外一种解法
// Easy to understand iterative Java solution
// https://discuss.leetcode.com/topic/31413/easy-to-understand-iterative-java-solution
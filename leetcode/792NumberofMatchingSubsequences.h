#include <algorithm>
#include <string>
#include <vector>
using namespace std;
// 74周周赛 未参加
// 自己的第一种方案 超时 所以这题没写出来
class Solution {
  public:
    int numMatchingSubseq(string S, vector<string> &words) {
        int res = 0;
        for (int i = 0; i < words.size(); i++) {
            if (S.size() >= words.size() && isSubsequence(words[i], S)) {
                res++;
            }
        }
        return res;
    }
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        for (; i < s.size() && j < t.size(); j++) {
            if (s[i] == t[j]) {
                i++;
            }
        }
        return i == s.size();
    }
};

// 来自LeetCode的答案 自己的改写版
// https://leetcode.com/problems/number-of-matching-subsequences/discuss/117602/JAVA-binary-search
class Solution_0 {
  public:
    int numMatchingSubseq(string S, vector<string> &words) {
        int res = 0;
        vector<vector<int>> alpha(26);
        for (int i = 0; i < S.size(); i++) {
            alpha[S[i] - 'a'].push_back(i);
        }
        for (string word : words) {
            res += isMatch(word, alpha);
        }
        return res;
    }
    int isMatch(string &word, vector<vector<int>> &alpha) {
        int index = 0;
        for (int c : word) {
            auto it = lower_bound(alpha[c - 'a'].begin(), alpha[c - 'a'].end(),
                                  index);
            if (it == alpha[c - 'a'].end() || index > *it) {
                return 0;
            }
            index = *it + 1;
        }
        return 1;
    }
};

// 第三种答案 来自LeetCode 比较奇葩
// https://leetcode.com/problems/number-of-matching-subsequences/discuss/117598/Faster-Java-solution-using-HashMap
/*
class Solution {
    public int numMatchingSubseq(String S, String[] words) {
        Map<Character, Deque<String>> map = new HashMap<>();
        for (char c = 'a'; c <= 'z'; c++) {
            map.putIfAbsent(c, new LinkedList<String>());
        }
        for (String word : words) {
            map.get(word.charAt(0)).addLast(word);
        }

        int count = 0;
        for (char c : S.toCharArray()) {
            Deque<String> queue = map.get(c);
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                String word = queue.removeFirst();
                if (word.length() == 1) {
                    count++;
                } else {
                    map.get(word.charAt(1)).addLast(word.substring(1));
                }
            }
        }
        return count;
    }
}
*/
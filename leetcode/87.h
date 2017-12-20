#include <string>
#include <map>
using namespace std;

class Solution {
  public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) {
            return true;
        }
        map<char, int> letters;
        for (int i = 0; i < s1.length(); i++) {
            letters[s1[i]]++;
            letters[s2[i]]--;
        }
        for (auto &a : letters) {
            if (a.second != 0)
                return false;
        }
        for (int i = 1; i < s1.length(); i++) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                isScramble(s1.substr(i), s2.substr(i))) {
                return true;
            }
            if (isScramble(s1.substr(0, i), s2.substr(s2.length() - i)) &&
                isScramble(s1.substr(i), s2.substr(0, s2.length() - i))) {
                return true;
            }
        }
        return false;
    }
};
// https://discuss.leetcode.com/topic/20094/my-c-solutions-recursion-with-cache-dp-recursion-with-cache-and-pruning-with-explanation-4ms
// leetcode的dp写法
/*
class Solution_0 {
  public:
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length())
            return false;
        int len = s1.length();
        bool[][][] F = new boolean[len][len][len + 1];
        for (int k = 1; k <= len; ++k)
            for (int i = 0; i + k <= len; ++i)
                for (int j = 0; j + k <= len; ++j)
                    if (k == 1)
                        F[i][j][k] = s1.charAt(i) == s2.charAt(j);
                    else
                        for (int q = 1; q < k && !F[i][j][k]; ++q) {
                            F[i][j][k] =
                                (F[i][j][q] && F[i + q][j + q][k - q]) ||
                                (F[i][j + k - q][q] && F[i + q][j][k - q]);
                        }
        return F[0][0][len];
    }
};
*/
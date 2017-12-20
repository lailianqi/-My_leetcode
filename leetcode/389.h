#include <string>
#include <vector>
using namespace std;
//这道题用了一分钟不到
class Solution {
  public:
    char findTheDifference(string s, string t) {
        vector<int> dir(26, 0);
        for (int i = 0; i < s.size(); i++) {
            dir[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            if (--dir[t[i] - 'a'] < 0) {
                return t[i];
            }
        }
        return 0;
    }
};

// leetcode的解法更加的巧妙
// https://discuss.leetcode.com/topic/55912/java-solution-using-bit-manipulation
class Solution_0 {
  public:
    char findTheDifference(string s, string t) {
        char c = t[s.size()];
        for (int i = 0; i < s.size(); i++) {
            c ^= s[i];
            c ^= t[i];
        }
        return c;
    }
};
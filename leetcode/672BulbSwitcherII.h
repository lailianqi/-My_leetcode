#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// 这题没写出来 直接看的答案
// 第一个链接是官方的题解
// https://leetcode.com/articles/bulb-switcher-ii/
// https://leetcode.com/problems/bulb-switcher-ii/discuss/107269/Java-O(1)
// https://leetcode.com/problems/bulb-switcher-ii/discuss/107271/C++-concise-code-O(1)
class Solution {
  public:
    int flipLights(int n, int m) {
        n = min(n, 3);
        if (m == 0)
            return 1;
        if (m == 1)
            return n == 1 ? 2 : n == 2 ? 3 : 4;
        if (m == 2)
            return n == 1 ? 2 : n == 2 ? 4 : 7;
        return n == 1 ? 2 : n == 2 ? 4 : 8;
    }
};
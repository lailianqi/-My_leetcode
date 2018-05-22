#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 这题没看懂 直接看的leetcode的答案 发现非常的需要技巧
// https://leetcode.com/problems/soup-servings/discuss/121711/C++JavaPython-When-N-greater-4800-just-return-1
// https://leetcode.com/problems/soup-servings/discuss/121740/Straightforward-Java-Recursion-with-Memorization
class Solution {
  public:
    double soupServings(int N) {
        return N >= 4800 ? 1.0 : helper((N + 24) / 25, (N + 24) / 25);
    }
    double helper(int a, int b) {
        if (a <= 0 && b <= 0) {
            return 0.5;
        }
        if (a <= 0) {
            return 1;
        }
        if (b <= 0) {
            return 0;
        }
        if (memo[a][b] > 0) {
            return memo[a][b];
        }
        memo[a][b] = 0.25 * (helper(a - 4, b) + helper(a - 3, b - 1) +
                             helper(a - 2, b - 2) + helper(a - 1, b - 3));
        return memo[a][b];
    }

  private:
    double memo[200][200];
};
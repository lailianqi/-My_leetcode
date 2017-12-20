#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
//最简单的做法，肯定超时
class Solution {
  public:
    int bulbSwitch(int n) {
        vector<bool> visit(n, true);
        for (int i = 2; i <= n; i++) {
            for (int j = i; j <= n; j = j + i) {
                visit[j - 1] = !visit[j - 1];
            }
        }
        return count(visit.begin(), visit.end(), true);
    }
};

// leetcode的答案
class Solution_0 {
  public:
    int bulbSwitch(int n) { return sqrt(n); }
};
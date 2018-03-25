#include <cmath>
using namespace std;

// 感觉像智力题一样 没想出来
// https://leetcode.com/problems/reach-a-number/discuss/112969/C++-O(1)-Solution-without-loop
class Solution {
  public:
    int reachNumber(int target) {
        target = abs(target);
        long long n = ceil((-1.0 + sqrt(1 + 8.0 * target)) / 2);
        long long sum = n * (n + 1) / 2;
        if (sum == target) {
            return n;
        }
        long long res = sum - target;
        if ((res & 1) == 0) {
            return n;
        } else {
            return n + ((n & 1) ? 2 : 1);
        }
    }
};

// 下面的解法的解释可能更加的详细 其实想法和上面的一样
// https://leetcode.com/problems/reach-a-number/discuss/112968/Short-JAVA-Solution-with-Explanation
class Solution_0 {
  public:
    int reachNumber(int target) {
        target = abs(target);
        long long n = ceil((-1.0 + sqrt(1 + 8.0 * target)) / 2);
        long long sum = n * (n + 1) / 2;
        long long res = sum - target;
        while (res % 2 != 0) {
            res += (++n);
        }
        return n;
    }
};
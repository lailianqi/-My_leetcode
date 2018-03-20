#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// 自己的第一种方案 暴力的解法直接写的
// leetcode的解法也是暴力的解法
// https://leetcode.com/problems/self-dividing-numbers/discuss/109424/Java-solution-with-explanation-no-toString()-conversion
// https://leetcode.com/problems/self-dividing-numbers/discuss/109458/JavaC++-Clean-Code
class Solution {
  public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int i = left; i <= right; i++) {
            if (isSelfDividingNumber(i)) {
                res.push_back(i);
            }
        }
        return res;
    }
    bool isSelfDividingNumber(int num) {
        int n = num;
        while (num > 0) {
            int divide = num % 10;
            if (divide == 0 || n % divide != 0) {
                return false;
            }
            num /= 10;
        }
        return true;
    }
};

// 来自LeetCode python的解法 写的非常的好
// https://leetcode.com/problems/self-dividing-numbers/discuss/109445/Python-Elegant-2-liner!!!

// class Solution(object):
//     def selfDividingNumbers(self, left, right):
//         is_self_dividing = lambda num: '0' not in str(num) and all(num %
//         int(digit) == 0 for digit in str(num)) return
//         filter(is_self_dividing, range(left, right + 1))
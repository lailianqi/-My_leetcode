// leetcode的答案
// https://discuss.leetcode.com/topic/49325/a-square-number-is-1-3-5-7-java-code
//二分法
class Solution {
  public:
    bool isPerfectSquare(int num) {
        if (num < 0) {
            return false;
        }
        if (num <= 1) {
            return true;
        }
        int left = 0, right = num / 2;
        while (left <= right) {
            long long mid = left + ((right - left) >> 1);
            long long temp = mid * mid;
            if (temp == num) {
                return true;
            } else if (temp < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};
// 1+3+5+7+...
/// https://discuss.leetcode.com/topic/49325/a-square-number-is-1-3-5-7-java-code
class Solution_0 {
  public:
    bool isPerfectSquare(int num) {
        int i = 1;
        while (num > 0) {
            num -= i;
            i += 2;
        }
        return num == 0;
    }
};

// Newton Method
// https://discuss.leetcode.com/topic/49325/a-square-number-is-1-3-5-7-java-code/2
// https://en.wikipedia.org/wiki/Integer_square_root#Using_only_integer_division
// https://discuss.leetcode.com/topic/49342/3-4-short-lines-integer-newton-most-languages
class Solution_1 {
  public:
    bool isPerfectSquare(int num) {
        long x = num;
        while (x * x > num) {
            x = (x + num / x) >> 1;
        }
        return x * x == num;
    }
};

//下面是最牛逼的方法的链接
//以后有时间再看
// https://discuss.leetcode.com/topic/49339/o-1-time-c-solution-inspired-by-q_rsqrt

//非常简单的题 直接二分查找就好
class Solution {
  public:
    int guessNumber(int n) {
        int left = 1, right = n;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (guess(mid) == -1) {
                right = mid - 1;
            } else if (guess(mid) == 1) {
                left = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
    int guess(int a) { return 0; } // API
};

// sp大神的二分查找
// https://discuss.leetcode.com/topic/51082/2-lines-as-usual
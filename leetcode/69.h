
//数据溢出
class Solution {
  public:
    int mySqrt(int x) {
        int i;
        for (i = 0; i <= x; i++) {
            if (i * i <= x && (i + 1) * (i + 1) > x)
                return i;
        }
        return i;
    }
};

class Solution_0 {
  public:
    int mySqrt(int x) {
        if (x == 0)
            return 0;
        int left = 1, right = x, mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (mid == x / mid) {
                return mid;
            } else if (mid > x / mid) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
};

class Solution_1 {
  public:
    int mySqrt(int x) {
        long r = x;
        while (r * r > x)
            r = (r + x / r) / 2;
        return r;
    }
};

void test() {
    Solution s;
    s.mySqrt(2147395600);
}

//自己的答案，这题还是挺简单的
class Solution {
  public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        int counter = 0;
        for (int i = 0; i < 32; i++) {
            if ((n >> i) & 1) {
                counter++;
            }
        }
        return counter == 1 ? true : false;
    }
};

// leetcode的解法，还不错
// https://discuss.leetcode.com/topic/17857/using-n-n-1-trick
class Solution_0 {
  public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        return !(n & (n - 1));
    }
};
class Solution {
  public:
    bool isUgly(int num) {
        if (num <= 0)
            return false;
        while (num % 2 == 0 || num % 3 == 0 || num % 5 == 0) {
            while (num % 2 == 0)
                num /= 2;
            while (num % 3 == 0)
                num /= 3;
            while (num % 5 == 0)
                num /= 5;
        }
        return num == 1;
    }
};

//下面是leetcode的简写的方案
// https://discuss.leetcode.com/topic/21785/2-4-lines-every-language
class Solution_0 {
  public:
    bool isUgly(int num) {
        for (int i = 2; i < 6 && num; i++)
            while (num % i == 0)
                num /= i;
        return num == 1;
    }
};
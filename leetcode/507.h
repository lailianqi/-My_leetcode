#include <unordered_set>
using namespace std;

//最简单的做法 暴力破解 但是过不了ac
class Solution {
  public:
    bool checkPerfectNumber(int num) {
        int res = 0;
        for (int i = 1; i <= num / 2; i++) {
            if (num % i == 0) {
                res += i;
            }
        }
        return res == num;
    }
};
//下面是leetcode链接的两个解法
// https://discuss.leetcode.com/topic/84259/simple-java-solution
class Solution_0 {
  public:
    bool checkPerfectNumber(int num) {
        int res = 0;
        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                res += i + (i != num / i ? num / i : 0);
            }
        }
        res++;
        return num != 1 && res == num;
    }
};
//上面解法的缩减版 在leetcode的测试样例中 去掉if判断也没有关系 照样ac 因为 n
// will not exceed 100,000,000. (1e8)
class Solution_1 {
  public:
    bool checkPerfectNumber(int num) {
        int res = 0;
        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                res += i + num / i;
            }
        }
        res++;
        return num != 1 && res == num;
    }
};

// leetcode的解法 作弊的解法
// https://discuss.leetcode.com/topic/84264/2-line-solution-c
class Solution_2 {
  public:
    bool checkPerfectNumber(int num) {
        static unordered_set<int> n = {6, 28, 496, 8128, 33550336};
        return n.count(num);
    }
};
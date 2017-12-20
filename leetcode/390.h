#include <vector>
using namespace std;
//最蠢的办法 肯定超时 通不过ac的
class Solution {
  public:
    int lastRemaining(int n) {
        vector<int> dp(n, 0);
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            dp[i - 1] = i;
        }
        while (dp.size() > 1) {
            vector<int> temp;
            if (flag) {
                for (int i = 0; i < dp.size() - 1; i += 2) {
                    temp.push_back(dp[i + 1]);
                }
            } else {
                for (int j = dp.size() - 1; j > 0; j -= 2) {
                    temp.insert(temp.begin(), dp[j - 1]);
                }
            }
            dp = temp;
            flag = !flag;
        }
        return dp[0];
    }
};
// leetcode的解法
// https://discuss.leetcode.com/topic/59293/java-easiest-solution-o-logn-with-explanation/2
class Solution_0 {
  public:
    int lastRemaining(int n) {
        int step = 1, result = 1, remainNum = n;
        bool leftToRight = true;
        while (remainNum > 1) {
            if (leftToRight || remainNum % 2 == 1) {
                result += step;
            }
            step = step * 2;
            remainNum = remainNum / 2;
            leftToRight = !leftToRight;
        }
        return result;
    }
};

//更加牛逼的写法 只需要一行
//这样的递归稍微有点不是完全理解
// leetcode的解法
// https://discuss.leetcode.com/topic/58042/c-1-line-solution-with-explanation
// http://blog.csdn.net/imfengyitong/article/details/70145948
// http://blog.csdn.net/MebiuW/article/details/52713918

class Solution_1 {
  public:
    int lastRemaining(int n) {
        return n == 1 ? 1 : 2 * (1 + n / 2 - lastRemaining(n / 2));
    }
};
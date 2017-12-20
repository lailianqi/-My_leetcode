#include <vector>
#include <climits>
using namespace std;
//参考263和264自己的答案
class Solution {
  public:
    int nthSuperUglyNumber(int n, vector<int> &primes) {
        vector<int> factor(primes.size(), 0);
        vector<int> dp(n, INT_MAX);
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            for (int k = 0; k < primes.size(); k++) {
                dp[i] = min(dp[i], dp[factor[k]] * primes[k]);
            }
            for (int k = 0; k < primes.size(); k++) {
                if (dp[i] == dp[factor[k]] * primes[k]) {
                    factor[k]++;
                }
            }
        }
        return dp[n - 1];
    }
};

//下面是leetcode的答案 和我的代码的思想是一样的，但更加的简洁
// https://discuss.leetcode.com/topic/31012/7-line-consice-o-kn-c-solution
class Solution_0 {
  public:
    int nthSuperUglyNumber(int n, vector<int> &primes) {
        vector<int> index(primes.size(), 0), ugly(n, INT_MAX);
        ugly[0] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < primes.size(); j++)
                ugly[i] = min(ugly[i], ugly[index[j]] * primes[j]);
            for (int j = 0; j < primes.size(); j++)
                index[j] += (ugly[i] == ugly[index[j]] * primes[j]);
        }
        return ugly[n - 1];
    }
};
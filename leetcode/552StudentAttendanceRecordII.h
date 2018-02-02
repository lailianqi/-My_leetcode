#include <vector>
using namespace std;
// 感觉这题好像数学题 所以直接看的答案 并没有动手去做 后来发现果然是数学题
// 来自LeetCode的答案
// https://discuss.leetcode.com/topic/86696/share-my-o-n-c-dp-solution-with-thinking-process-and-explanation
/*
公式：
P(n) = A(n - 1) + P(n - 1) + L(n - 1), n ≥ 2.
L(n) = A(n - 1) + P(n - 1) + A(n - 2) + P(n - 2), n ≥ 3.
A(n) = A(n - 1) + A(n - 2) + A(n - 3), n ≥ 4.
*/

class Solution {
  public:
    int checkRecord(int n) {
        int m = 1000000007;
        int *A = new int[n];
        int *P = new int[n];
        int *L = new int[n];
        P[0] = 1;
        L[0] = 1;
        L[1] = 3;
        A[0] = 1;
        A[1] = 2;
        A[2] = 4;
        if (n == 1) {
            return 3;
        }
        for (int i = 1; i < n; i++) {
            A[i - 1] %= m;
            P[i - 1] %= m;
            L[i - 1] %= m;

            P[i] = ((A[i - 1] + P[i - 1]) % m + L[i - 1]) % m;

            if (i > 1)
                L[i] =
                    ((A[i - 1] + P[i - 1]) % m + (A[i - 2] + P[i - 2]) % m) % m;
            if (i > 2)
                A[i] = ((A[i - 1] + A[i - 2]) % m + A[i - 3]) % m;
        }

        return ((A[n - 1] % m + P[n - 1] % m) % m + L[n - 1] % m) % m;
    }
};

// 一个更加简单的方法 来自LeetCode
/*
dp[i]the number of all possible attendance (without 'A') records with length i :
end with "P": dp[i-1]
end with "PL": dp[i-2]
end with "PLL": dp[i-3]
end with "LLL": is not allowed
so dp[i] = dp[i-1] + dp[i-2] + dp[i-3]
the number of all possible attendance (with 'A') records with length n:
∑dp[i] *dp[n-1-i] i = 0,1,...,n-1
Time Complexity O(n)
Space Complexity O(n)
In code nums[i+1] means dp[i]
*/
// https://discuss.leetcode.com/topic/86485/python-dp-with-explanation
// https://discuss.leetcode.com/topic/86485/python-dp-with-explanation/2
class Solution_0 {
  public:
    int checkRecord(int n) {
        if (n == 1) {
            return 3;
        }
        vector<long> nums = {1, 1, 2};
        int i = 2, m = 1000000007;
        while (i < n) {
            nums.push_back(((nums[i] + nums[i - 1]) % m + nums[i - 2]) % m);
            i++;
        }
        long result = ((nums[n] + nums[n - 1]) % m + nums[n - 2]) % m;
        for (int i = 0; i < n; i++) {
            result += (nums[i + 1] * nums[n - i]) % m;
            result %= m;
        }
        return (int)result;
    }
};

// 速度更快的解法 但是过于复杂了
// https://discuss.leetcode.com/topic/86526/improving-the-runtime-from-o-n-to-o-log-n?page=1
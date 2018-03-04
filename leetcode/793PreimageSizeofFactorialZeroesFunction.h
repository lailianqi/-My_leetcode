

// 74周周赛 未参加
// 难题 没写出来 直接看的LeetCode的答案
// https://leetcode.com/problems/preimage-size-of-factorial-zeroes-function/solution/
// https://leetcode.com/problems/preimage-size-of-factorial-zeroes-function/discuss/117632/binary-search-python-code-40ms
class Solution {
  public:
    int preimageSizeFZF(int K) {
        int lo = K, hi = 5 * K + 1;
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            int zmi = zeta(mi);
            if (zmi == K)
                return 5;
            else if (zmi < K)
                lo = mi + 1;
            else
                hi = mi;
        }
        return 0;
    }
    int zeta(int x) {
        if (x == 0)
            return 0;
        return x / 5 + zeta(x / 5);
    }
};
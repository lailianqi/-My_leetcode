#include <bitset>
using namespace std;
// LeetCode第70周周赛
// 比赛中没有写出 写的答案是超时的
// 下面是LeetCode的答案 看了答案 豁然开朗
// https://discuss.leetcode.com/topic/119462/my-3-lines-c-recursive-solution
class Solution {
  public:
    int kthGrammar(int N, int K) {
        if (N == 1) {
            return 0;
        }
        if (K % 2 == 0) {
            return kthGrammar(N - 1, K / 2) == 0 ? 1 : 0;
        } else {
            return kthGrammar(N - 1, (K + 1) / 2) == 0 ? 0 : 1;
        }
    }
};

// 还有更加牛逼的解法 来自LeetCode 暂时不知道理论依据
// https://discuss.leetcode.com/topic/119468/python-1-line
// https://discuss.leetcode.com/topic/119462/my-3-lines-c-recursive-solution/3
class Solution_0 {
  public:
    int kthGrammar(int N, int K) { return bitset<32>(K - 1).count() & 1; }
};
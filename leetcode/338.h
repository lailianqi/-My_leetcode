#include <vector>
#include <cmath>
using namespace std;
//自己 不符合题目要求的写法
class Solution {
  public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1, 0);
        for (int i = 0; i <= num; i++) {
            int temp = i, count = 0;
            for (int j = 0; j < 32; j++) {
                if (temp & 1) {
                    count++;
                }
                temp = temp >> 1;
            }
            res[i] = count;
        }
        return res;
    }
};
//自己想出来的 O(n)的方法 真是牛逼
class Solution_0 {
  public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1, 0);
        for (int i = 1; i <= num; i++) {
            int exponential = log2(i);
            int temp = pow(2, exponential);
            res[i] = i == temp ? 1 : res[temp] + res[i - temp];
        }
        return res;
    }
};

//下面是leetcode的解法 都非常的牛逼
// https://discuss.leetcode.com/topic/40162/three-line-java-solution/2
// https://discuss.leetcode.com/topic/40262/four-lines-c-time-o-n-space-o-n
//技巧在i & (i - 1)
class Solution_1 {
  public:
    vector<int> countBits(int num) {
        vector<int> ret(num + 1, 0);
        for (int i = 1; i <= num; ++i)
            ret[i] = ret[i & (i - 1)] + 1;
        return ret;
    }
};
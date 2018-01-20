#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
//自己的第一种方案 但是超时了
class Solution {
  public:
    int findMaxLength(vector<int> &nums) {
        int m = nums.size(), res = 0;
        vector<int> sums(m + 1, 0);
        for (int i = 0; i < m; i++) {
            sums[i + 1] = sums[i] + (nums[i] == 0 ? -1 : 1);
        }
        for (int i = 0; i <= m; i++) {
            for (int j = i + 1; j <= m; j++) {
                if (sums[j] - sums[i] == 0) {
                    res = max(res, j - i);
                }
            }
        }
        return res;
    }
};

// 看了LeetCode的答案，是上面方法的改进版 大大提升了效率
// https://discuss.leetcode.com/topic/79906/easy-java-o-n-solution-presum-hashmap
class Solution_0 {
  public:
    int findMaxLength(vector<int> &nums) {
        int res = 0, sum = 0;
        unordered_map<int, int> dir;
        dir[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            sum += (nums[i] == 0 ? -1 : 1);
            if (dir.count(sum)) {
                res = max(res, i - dir[sum]);
            } else {
                dir[sum] = i;
            }
        }
        return res;
    }
};

// sp大神的写法
// https://discuss.leetcode.com/topic/79977/python-and-java-with-little-tricks-incl-a-oneliner
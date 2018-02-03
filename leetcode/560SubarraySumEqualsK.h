#include <unordered_map>
#include <vector>
using namespace std;
//自己的第一种方案 成功ac 但是程序效率不高
class Solution {
  public:
    int subarraySum(vector<int> &nums, int k) {
        int m = nums.size(), res = 0;
        vector<int> sum(m + 1, 0);
        for (int i = 0; i < m; i++) {
            sum[i + 1] = sum[i] + nums[i];
        }
        for (int i = m; i >= 1; i--) {
            for (int j = i - 1; j >= 0; j--) {
                if (sum[i] - sum[j] == k) {
                    res++;
                }
            }
        }
        return res;
    }
};

// 自己的第二种方案 用了hashmap的方法 以及Prefix Sum的方法
// LeetCode上面类似的答案
// https://discuss.leetcode.com/topic/87850/java-solution-presum-hashmap
// https://discuss.leetcode.com/topic/87866/python-simple-with-explanation
// https://discuss.leetcode.com/topic/88041/super-simple-python
class Solution_0 {
  public:
    int subarraySum(vector<int> &nums, int k) {
        int m = nums.size(), res = 0;
        unordered_map<int, int> dir;
        dir[0] = 1;
        for (int i = 0, sum = 0; i < m; i++) {
            sum += nums[i];
            res += dir[sum - k];
            dir[sum]++;
        }
        return res;
    }
};
void test() {
    Solution_0 s;
    vector<int> nums = {1, 1, 1};
    s.subarraySum(nums, 2);
}
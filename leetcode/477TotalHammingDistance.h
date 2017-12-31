#include <vector>
using namespace std;
//自己的第一种想法 暴力破解 过不了oj
class Solution {
  public:
    int totalHammingDistance(vector<int> &nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                res += hammingDistance(nums[i], nums[j]);
            }
        }
        return res;
    }
    int hammingDistance(int x, int y) {
        int num = x ^ y, res = 0;
        for (int i = 0; i < 32; i++) {
            res += (num & 1);
            num >>= 1;
        }
        return res;
    }
};

// 自己没有想到优化方案 直接看的leetcode的答案
// https://discuss.leetcode.com/topic/72092/java-o-n-time-o-1-space
class Solution_0 {
  public:
    int totalHammingDistance(vector<int> &nums) {
        int res = 0, m = nums.size();
        for (int i = 0; i < 32; i++) {
            int oneNum = 0;
            for (int j = 0; j < nums.size(); j++) {
                oneNum += (nums[j] >> i) & 1;
            }
            res += oneNum * (m - oneNum);
        }
        return res;
    }
};

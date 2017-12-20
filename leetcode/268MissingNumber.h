#include <vector>
using namespace std;
//自己的写法，空间不是常数空间
class Solution {
  public:
    int missingNumber(vector<int> &nums) {
        vector<int> res(nums.size() + 1, -1);
        for (int i = 0; i < nums.size(); i++) {
            res[nums[i]] = 1;
        }
        for (int i = 0; i < res.size(); i++) {
            if (res[i] == -1) {
                return i;
            }
        }
        return -1;
    }
};
// leetcode的解法
//这个解法非常的好
// https://discuss.leetcode.com/topic/24535/4-line-simple-java-bit-manipulate-solution-with-explaination
class Solution_0 {
  public:
    int missingNumber(vector<int> &nums) {
        int XOR = 0;
        for (int i = 0; i < nums.size(); i++) {
            XOR = XOR ^ i ^ nums[i];
        }
        return XOR ^ nums.size();
    }
};
#include <vector>
using namespace std;
//和leetcode的方法相差无几
class Solution {
  public:
    int majorityElement(vector<int> &nums) {
        int num = nums[0], count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (num == nums[i]) {
                count++;
            } else {
                count--;
                if (count < 0) {
                    num = nums[i];
                    count = 1;
                }
            }
        }
        return num;
    }
};

//下面是leetcode关于bit的操作
// https://discuss.leetcode.com/topic/28601/java-solutions-sorting-hashmap-moore-voting-bit-manipulation/19

class Solution_0 {
  public:
    int majorityElement(vector<int> &nums) {
        vector<int> bit(32, 0);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < 32; j++) {
                bit[j] += (nums[i] >> j) & 1;
            }
        }
        int majority = 0;
        for (int j = 0; j < 32; j++) {
            bit[j] = bit[j] > (nums.size() / 2) ? 1 : 0;
            majority += bit[j] << j;
        }
        return majority;
    }
};

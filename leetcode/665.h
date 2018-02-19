#include <algorithm>
#include <string>
#include <vector>
using namespace std;
// 简单题 greedy的解法
class Solution {
  public:
    bool checkPossibility(vector<int> &nums) {
        int counter = 0;
        for (int i = 1; i < nums.size() && counter <= 1; i++) {
            if (nums[i] < nums[i - 1]) {
                if (i < 2 || nums[i] >= nums[i - 2]) {
                    nums[i - 1] = nums[i];
                } else {
                    nums[i] = nums[i - 1];
                }
                counter++;
            }
        }
        return counter <= 1;
    }
};
#include <vector>
#include <climits>
using namespace std;
// runtime beats 54.51 % of cpp submissions
class Solution {
  public:
    int maxSubArray(vector<int> &nums) {
        int sum = INT_MIN, b = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (b > 0) {
                b += nums[i];
            } else {
                b = nums[i];
            }
            if (b > sum) {
                sum = b;
            }
        }
        return sum;
    }
};

// Leetcode 3ms的答案
class Solution_0 {
  public:
    int maxSubArray(vector<int> &nums) {
        int sol = INT_MIN;
        int sum = 0;
        for (int n : nums) {
            sum = max(n, sum + n);
            sol = max(sol, sum);
        }
        return sol;
    }
};
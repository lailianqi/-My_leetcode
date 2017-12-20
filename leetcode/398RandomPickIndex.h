#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
  public:
    Solution(vector<int> nums) { this->nums = nums; }

    int pick(int target) {
        int res = 0, cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                if (rand() % (cnt + 1) == cnt) {
                    res = i;
                }
                cnt++;
            }
        }
        return res;
    }

  private:
    vector<int> nums;
};
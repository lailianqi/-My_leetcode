#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

class Solution {
  public:
    Solution(vector<int> nums) { this->nums = nums; }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() { return nums; }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> result(nums);
        if (!result.empty()) {
            for (int j = 1; j < result.size(); j++) {
                int i = rand() % (j + 1);
                swap(result[i], result[j]);
            }
        }
        return result;
    }

  private:
    vector<int> nums;
};

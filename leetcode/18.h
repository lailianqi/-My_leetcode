#include <vector>
#include <algorithm>
using namespace std;
class Solution {
  public:
    vector<vector<int> > fourSum(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > answer;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                for (int j = nums.size() - 1; j >= i + 1; j--) {
                    if (j == nums.size() - 1 ||
                        (j < nums.size() - 1 && nums[j] != nums[j + 1])) {
                        int low = i + 1, high = j - 1;
                        int sum = target - nums[i] - nums[j];
                        while (low < high) {
                            if (nums[low] + nums[high] == sum) {
                                vector<int> v;
                                v.push_back(nums[i]);
                                v.push_back(nums[low]);
                                v.push_back(nums[high]);
                                v.push_back(nums[j]);
                                answer.push_back(v);
                                while (low < high && nums[low] == nums[low + 1])
                                    low++;
                                while (low < high &&
                                       nums[high] == nums[high - 1])
                                    high--;
                                low++, high--;
                            } else if (nums[low] + nums[high] < sum) {
                                low++;
                            } else {
                                high--;
                            }
                        }
                    }
                }
            }
        }
        return answer;
    }
};
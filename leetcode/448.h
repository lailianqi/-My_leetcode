#include <vector>
#include <cmath>
using namespace std;
//直接参考442的解法稍作修改就可以直接写出来 成功ac
class Solution {
  public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        vector<int> res;
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
            else
                i++;
        }
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1)
                res.push_back(i + 1);
        }
        return res;
    }
};
//也是442题的答案稍微修改的解法
// leetcode的解法 与这个是相同的
// https://discuss.leetcode.com/topic/65738/java-accepted-simple-solution
class Solution_0 {
  public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;
            if (nums[index] > 0) {
                nums[index] = -nums[index];
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};

void test() {
    Solution s;
    vector<int> nums = {2, 1};
    s.findDisappearedNumbers(nums);
}
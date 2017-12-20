#include <vector>
using namespace std;
//这个方案不行，无法保证不是零的数的原有的顺序
class Solution {
  public:
    void moveZeroes(vector<int> &nums) {
        for (int i = 0, j = nums.size() - 1; i < j;) {
            while (nums[i] != 0 && i < j)
                i++;
            while (nums[j] == 0 && i < j)
                j--;
            swap(nums[i++], nums[j--]);
        }
    }
};
//自己写的第二种方案
class Solution_0 {
  public:
    void moveZeroes(vector<int> &nums) {
        for (int i = 0, j = 0; i < nums.size() && j < nums.size();) {
            while (nums[i] != 0 && i < nums.size())
                i++;
            j = i + 1;
            while (j < nums.size() && nums[j] == 0)
                j++;
            if (j < nums.size()) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
    }
};
// leetcode的答案
// https://discuss.leetcode.com/topic/24716/simple-o-n-java-solution-using-insert-index
// https://discuss.leetcode.com/topic/24745/c-accepted-code
class Solution_1 {
  public:
    void moveZeroes(vector<int> &nums) {
        int pos = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[pos++] = nums[i];
            }
        }
        for (int j = pos; j < nums.size(); j++) {
            nums[j] = 0;
        }
    }
};
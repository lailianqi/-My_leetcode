#include <vector>
using namespace std;
//自己的答案，感觉超级的完美
//答案是不能修改原有的数组，所以该答案是不符合要求的
class Solution {
  public:
    int findDuplicate(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i];
            while (nums[i] != i + 1) {
                if (nums[i] == nums[nums[i] - 1])
                    return nums[i];
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        return 0;
    }
};
// leetcode的答案
// https://discuss.leetcode.com/topic/25685/java-o-n-time-and-o-1-space-solution-similar-to-find-loop-in-linkedlist
class Solution_0 {
  public:
    int findDuplicate(vector<int> &nums) {
        int n = nums.size();
        int walker = n, runner = n;
        do {
            walker = nums[walker - 1];
            runner = nums[nums[runner - 1] - 1];
        } while (walker != runner);
        int entry = n;
        while (entry != walker) {
            walker = nums[walker - 1];
            entry = nums[entry - 1];
        }
        return walker;
    }
};
// https://discuss.leetcode.com/topic/25685/java-o-n-time-and-o-1-space-solution-similar-to-find-loop-in-linkedlist/8
class Solution_1 {
  public:
    int findDuplicate(vector<int> &nums) {
        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
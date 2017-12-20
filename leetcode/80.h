#include <vector>
using namespace std;

class Solution {
  public:
    int removeDuplicates(vector<int> &nums) {
        int length = 0;
        int counter = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                nums[length++] = nums[i];
                counter = 1;
            } else if (counter >= 2) {
                counter++;
            } else {
                nums[length++] = nums[i];
                counter++;
            }
        }
        return length;
    }
};

// leetCode 的好方法
class Solution_0 {
  public:
    int removeDuplicates(vector<int> &nums) {
        int i = 0;
        for (int n : nums)
            if (i < 2 || n > nums[i - 2])
                nums[i++] = n;
        return i;
    }
};

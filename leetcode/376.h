#include <vector>
#include <stack>
using namespace std;
/*
Input: [1,7,4,9,2,5]
Output: 6
The entire sequence is a wiggle sequence.
Input: [1,17,5,10,13,15,10,5,16,8]
Output: 7
There are several subsequences that achieve this length. One is
[1,17,10,13,10,16,8].
Input: [1,2,3,4,5,6,7,8,9]
Output: 2
*/
//题目简单 也知道怎么写 但是没有去写 因为按照原本的思路 写出来的代码也非常的ugly
// leetcode的答案
// https://discuss.leetcode.com/topic/51946/very-simple-java-solution-with-detail-explanation/4
class Solution {
  public:
    int wiggleMaxLength(vector<int> &nums) {
        int m = nums.size(), result = 2, k = 1;
        if (m <= 1) {
            return m;
        }
        while (k < m && nums[k] == nums[k - 1])
            k++;
        if (k == m)
            return 1;
        bool isIncreasing = nums[k] > nums[k - 1];
        for (int i = k + 1; i < m; i++) {
            if ((isIncreasing && nums[i] < nums[i - 1]) ||
                (!isIncreasing && nums[i] > nums[i - 1])) {
                isIncreasing = !isIncreasing;
                result++;
            }
        }
        return result;
    }
};

// leetcode的答案
// dp的写法 画图可直接观察此题dp的原理
// https://discuss.leetcode.com/topic/52076/easy-understanding-dp-solution-with-o-n-java-version/6
class Solution_1 {
  public:
    int wiggleMaxLength(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        int up = 1, down = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                up = down + 1;
            } else if (nums[i] < nums[i - 1]) {
                down = up + 1;
            }
        }
        return max(up, down);
    }
};
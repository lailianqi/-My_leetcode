#include <cmath>
#include <vector>
using namespace std;
// 自己的第一种方案 成功ac
class Solution {
  public:
    vector<int> findErrorNums(vector<int> &nums) {
        int errorNum = 0, missNum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[abs(nums[i]) - 1] > 0) {
                nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
            } else {
                errorNum = abs(nums[i]);
                break;
            }
        }
        missNum ^= errorNum;
        for (int i = 0; i < nums.size(); i++) {
            missNum ^= (i + 1) ^ abs(nums[i]);
        }
        return {errorNum, missNum};
    }
};

// LeetCode的答案 另外的一种写法 其实差不多
// https://leetcode.com/problems/set-mismatch/discuss/105507/Java-O(n)-Time-O(1)-Space
class Solution_0 {
  public:
    vector<int> findErrorNums(vector<int> &nums) {
        int errorNum = 0, missNum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[abs(nums[i]) - 1] > 0) {
                nums[abs(nums[i]) - 1] *= -1;
            } else {
                errorNum = abs(nums[i]);
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                missNum = i + 1;
                break;
            }
        }
        return {errorNum, missNum};
    }
};

// 另外一个好的解法
// https://leetcode.com/problems/set-mismatch/discuss/105515/C++-6-lines-solution-with-explanation
class Solution_1 {
  public:
    vector<int> findErrorNums(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1)
                return {nums[i], i + 1};
        }
        return {-1, -1};
    }
};
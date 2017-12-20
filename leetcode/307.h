#include <vector>
using namespace std;
//这种解法超时
class NumArray {
  public:
    NumArray(vector<int> nums) {
        result = vector<int>(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            result[i] = (i == 0 ? 0 : result[i - 1]) + nums[i];
        }
    }

    void update(int i, int val) {
        int temp = result[i] - (i == 0 ? 0 : result[i - 1]) - val;
        for (int k = i; k < result.size(); k++) {
            result[k] -= temp;
        }
    }

    int sumRange(int i, int j) {
        return result[j] - (i == 0 ? 0 : result[i - 1]);
    }

  private:
    vector<int> result;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */

//下面的解法是二叉索引树的解法 非常的梦幻
// http://www.cnblogs.com/grandyang/p/4985506.html
class Solution {
    class NumArray {
      public:
        NumArray(vector<int> nums) {
            nums.resize(nums.size() + 1);
            bit.resize(nums.size() + 1);
            for (int i = 0; i < nums.size(); ++i) {
                update(i, nums[i]);
            }
        }

        void update(int i, int val) {
            int diff = val - num[i + 1];
            for (int j = i + 1; j < num.size(); j += (j & -j)) {
                bit[j] += diff;
            }
            num[i + 1] = val;
        }

        int sumRange(int i, int j) { return getSum(j + 1) - getSum(i); }
        int getSum(int i) {
            int res = 0;
            for (int j = i; j > 0; j -= (j & -j)) {
                res += bit[j];
            }
            return res;
        }

      private:
        vector<int> num;
        vector<int> bit;
    };
};
// leetcode的解法
// 非常的牛逼
// https://discuss.leetcode.com/topic/31599/java-using-binary-indexed-tree-with-clear-explanation
class Solution_0 {
    class NumArray {
      public:
        NumArray(vector<int> nums) {
            this->nums = nums;
            this->bit = vector<int>(nums.size() + 1, 0);
            for (int i = 0; i < nums.size(); i++) {
                for (int j = i + 1; j < bit.size(); j += (j & -j)) {
                    bit[j] += nums[i];
                }
            }
        }

        void update(int i, int val) {
            int diffenence = val - nums[i];
            nums[i] = val;
            for (int j = i + 1; j < bit.size(); j += (j & -j)) {
                bit[j] += diffenence;
            }
        }

        int sumRange(int i, int j) { return getSum(j + 1) - getSum(i); }
        int getSum(int i) {
            int res = 0;
            for (int j = i; j > 0; j -= (j & -j)) {
                res += bit[j];
            }
            return res;
        }

      private:
        vector<int> nums;
        vector<int> bit;
    };
};

//第三种写法 segment tree

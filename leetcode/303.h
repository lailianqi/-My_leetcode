#include <vector>
using namespace std;
//自己写的答案，速度还是不够快 虽然击败的人够多 还是不够快
// Your runtime beats 78.73 % of cpp submissions.
//自己的想法和leetcode的所谓的最佳的答案一样。下面是链接
// https://discuss.leetcode.com/topic/29194/java-simple-o-n-init-and-o-1-query-solution
class NumArray {
  public:
    NumArray(vector<int> nums) {
        result = vector<int>(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            result[i] = (i == 0 ? 0 : result[i - 1]) + nums[i];
        }
    }

    int sumRange(int i, int j) {
        return result[j] - (i == 0 ? 0 : result[i - 1]);
    }

  private:
    vector<int> result;
};
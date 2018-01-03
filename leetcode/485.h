#include <vector>
using namespace std;
//自己的第一种方案 成功ac 但是觉得代码太长了
// leetcode上面有类似写法 不同是我把max操作放在==0的时候
// 而leetcode是==1时执行max操作
// https://discuss.leetcode.com/topic/75430/easy-java-solution
class Solution {
  public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int res = 0, counter = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                counter++;
            } else {
                res = max(res, counter);
                counter = 0;
            }
        }
        res = max(res, counter);
        return res;
    }
};

// 自己对上面方案的改进  但是每次都会执行max操作
// leetcode上面类似的答案
// https://discuss.leetcode.com/topic/75437/java-4-lines-concise-solution-with-explanation
class Solution_0 {
  public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int res = 0, counter = 0;
        for (int i = 0; i < nums.size(); i++) {
            res = max(res, counter = nums[i] == 0 ? 0 : counter + 1);
        }
        return res;
    }
};
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;
//自己的第一种方案 一次性ac 但是运行效率太低 而且代码太难看
class Solution {
  public:
    vector<int> nextGreaterElement(vector<int> &nums) {
        int m = nums.size();
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            int j = (i + 1) % m;
            while (j != i) {
                if (nums[j] > nums[i]) {
                    res.push_back(nums[j]);
                    break;
                }
                j = (j + 1) % m;
            }
            if (j == i) {
                res.push_back(-1);
            }
        }
        return res;
    }
};
// leetcode的解法 非常的巧妙 第一个链接算法比较简单易懂
// https://discuss.leetcode.com/topic/77923/java-10-lines-and-c-12-lines-linear-time-complexity-o-n-with-explanation
// 第二个链接的算法画图可知原理 比较难懂
// https://discuss.leetcode.com/topic/77881/typical-ways-to-solve-circular-array-problems-java-solution/2
class Solution_0 {
  public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        stack<int> stacks;
        int m = nums.size();
        vector<int> res(m, -1);
        for (int i = 0; i < 2 * m; i++) {
            int num = nums[i % m];
            while (!stacks.empty() && nums[stacks.top()] < num) {
                res[stacks.top()] = num;
                stacks.pop();
            }
            stacks.push(i % m);
        }
        return res;
    }
};
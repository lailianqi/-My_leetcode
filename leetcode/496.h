#include <vector>
#include <map>
#include <stack>
using namespace std;
//自己的第一种解法 成功ac 但是代码太长
class Solution {
  public:
    vector<int> nextGreaterElement(vector<int> &findNums, vector<int> &nums) {
        map<int, int> dir;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            dir[nums[i]] = i;
        }
        for (int i = 0; i < findNums.size(); i++) {
            for (int j = dir[findNums[i]]; j < nums.size(); j++) {
                if (findNums[i] < nums[j]) {
                    res.push_back(nums[j]);
                    break;
                }
                if (j == nums.size() - 1) {
                    res.push_back(-1);
                }
            }
        }
        return res;
    }
};

// leetcode的答案 用的堆栈 下面是自己对leetcode答案的稍微的修改版
// https://discuss.leetcode.com/topic/77916/java-10-lines-linear-time-complexity-o-n-with-explanation?page=1
// https://discuss.leetcode.com/topic/78397/c-stack-unordered_map
class Solution_0 {
  public:
    vector<int> nextGreaterElement(vector<int> &findNums, vector<int> &nums) {
        stack<int> stacks;
        map<int, int> dir;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            while (!stacks.empty() && stacks.top() < nums[i]) {
                dir[stacks.top()] = nums[i];
                stacks.pop();
            }
            stacks.push(nums[i]);
        }
        for (int i = 0; i < findNums.size(); i++) {
            res.push_back(dir.count(findNums[i]) ? dir[findNums[i]] : -1);
        }
        return res;
    }
};
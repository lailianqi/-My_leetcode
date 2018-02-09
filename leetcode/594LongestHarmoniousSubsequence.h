#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
// 最普遍的做法
// https://discuss.leetcode.com/topic/89990/simple-java-hashmap-solution
// https://discuss.leetcode.com/topic/89994/python-straightforward-with-explanation
class Solution {
  public:
    int findLHS(vector<int> &nums) {
        unordered_map<int, int> dir;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            dir[nums[i]]++;
        }
        for (auto it : dir) {
            if (dir.count(it.first - 1)) {
                res = max(res, it.second + dir[it.first - 1]);
            }
        }
        return res;
    }
};

// 另外的一种写法 直接排序
// https://discuss.leetcode.com/topic/89990/simple-java-hashmap-solution/17
class Solution_0 {
  public:
    int findLHS(vector<int> &nums) {
        int res = 0, start = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size();) {
            if (nums[i] - nums[start] == 0) {
                i++;
            } else if (nums[i] - nums[start] == 1) {
                res = max(res, i - start + 1);
                i++;
            } else {
                start++;
            }
        }
        return res;
    }
};
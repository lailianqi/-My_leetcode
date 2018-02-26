#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
// 自己的第一种方案 成功ac
// LeetCode上面类似的答案
// https://leetcode.com/problems/degree-of-an-array/discuss/108651/straightforward-c++-solution-35ms
// https://leetcode.com/problems/degree-of-an-array/discuss/108660/Java-O(n)-Time-O(n)-Space
// https://leetcode.com/problems/degree-of-an-array/discuss/108674/Concise-c++-solution-using-hash-map.-O(n)-time
class Solution {
  public:
    int findShortestSubArray(vector<int> &nums) {
        unordered_map<int, vector<int>> dir;
        int maxSize = 0, res = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            dir[nums[i]].push_back(i);
        }
        for (auto &element : dir) {
            maxSize = max(maxSize, (int)element.second.size());
        }
        for (auto &element : dir) {
            if (element.second.size() == maxSize) {
                res = min(res,
                          element.second.back() - element.second.front() + 1);
            }
        }
        return res;
    }
};

// leetcode上面python的写法
// https://leetcode.com/problems/degree-of-an-array/discuss/108666/Python-easy-and-concise-solution
// def findShortestSubArray(self, nums):
//         c = collections.Counter(nums)
//         first, last = {}, {}
//         for i, v in enumerate(nums):
//             first.setdefault(v, i)
//             last[v] = i
//         degree = max(c.values())
//         return min(last[v] - first[v] + 1 for v in c if c[v] == degree)
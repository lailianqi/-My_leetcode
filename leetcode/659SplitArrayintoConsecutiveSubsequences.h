#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 这题没写出来 直接看的答案 感觉写的还是非常的巧妙的
// https://leetcode.com/problems/split-array-into-consecutive-subsequences/discuss/106496/Java-O(n)-Time-O(n)-Space
// http://blog.csdn.net/zjucor/article/details/77152382
// https://www.cnblogs.com/pk28/p/7384602.html

// 官方的题解讲的最清楚 用了贪心的思想
// https://leetcode.com/articles/split-array-into-consecutive-subsequences/
// https://leetcode.com/problems/split-array-into-consecutive-subsequences/solution/
class Solution {
  public:
    bool isPossible(vector<int> &nums) {
        unordered_map<int, int> dict, need_freq;
        for (auto &ele : nums) {
            dict[ele]++;
        }
        for (auto &ele : nums) {
            if (dict[ele] != 0) {
                if (need_freq[ele] > 0) {
                    dict[ele]--;
                    need_freq[ele]--;
                    need_freq[ele + 1]++;
                } else if (dict[ele + 1] > 0 && dict[ele + 2] > 0) {
                    dict[ele]--;
                    dict[ele + 1]--;
                    dict[ele + 2]--;
                    need_freq[ele + 3]++;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
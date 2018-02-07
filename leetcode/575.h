#include <algorithm>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;
// 自己的第一种方案 成功ac
class Solution {
  public:
    int distributeCandies(vector<int> &candies) {
        set<int> candyKindSet;
        int m = candies.size();
        for (int i = 0; i < m; i++) {
            candyKindSet.insert(candies[i]);
        }
        return min(m / 2, (int)candyKindSet.size());
    }
};
// 自己的第二种方案 改成unordered_set 快太多了
// LeetCode上面的类似的答案 思想和写法一模一样
// https://discuss.leetcode.com/topic/88507/java-solution-3-lines-hashset
// https://discuss.leetcode.com/topic/88510/python-straightforward-with-explanation
class Solution_0 {
  public:
    int distributeCandies(vector<int> &candies) {
        unordered_set<int> candyKindSet;
        int m = candies.size();
        for (int i = 0; i < m; i++) {
            candyKindSet.insert(candies[i]);
        }
        return min(m / 2, (int)candyKindSet.size());
    }
};

// 一种更加短的写法 来自LeetCode
// https://discuss.leetcode.com/topic/88500/c-clean-code-2-solutions-set-and-sort
class Solution_1 {
  public:
    int distributeCandies(vector<int> &candies) {
        return min(unordered_set<int>(candies.begin(), candies.end()).size(),
                   candies.size() / 2);
    }
};
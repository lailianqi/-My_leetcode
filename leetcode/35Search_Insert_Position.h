#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 好题 第二遍刷的时候发现是对于lower_bound的理解非常的有好处的题

class Solution {
  public:
    int searchInsert(vector<int> &nums, int target) {
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] < target) {
                i++;
            } else if (nums[i] == target) {
                return i;
            } else {
                break;
            }
        }
        return i;
    }
    //直接二分查找，返回left
    int searchInsert1(vector<int> &nums, int target) {}
};

// 第二遍刷的时候自己添加的方案 leetcode上面类似的答案
// https://leetcode.com/problems/search-insert-position/discuss/15391/A-simple-CPP-solution-with-lower_bound
// https://leetcode.com/problems/search-insert-position/discuss/15101/C++-O(logn)-Binary-Search-that-handles-duplicate
class Solution_0 {
  public:
    int searchInsert(vector<int> &nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};
void test() {
    Solution s;
    vector<int> v = {1, 3, 5, 6};
    cout << s.searchInsert(v, 5);
}
#include <bits/stdc++.h>
using namespace std;
// Your runtime beats 90.57 % of cpp submissions.
class Solution {
  public:
    bool containsDuplicate(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return true;
            }
        }
        return false;
    }
};

// leetCode上面更简单的做法
class Solution_0 {
  public:
    bool containsDuplicate(vector<int> &nums) {
        return nums.size() > set<int>(nums.begin(), nums.end()).size();
    }
};
#include <vector>
#include <iostream>
using namespace std;

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
    int searchInsert1(vector<int> &nums, int target) {
       
    }
};

void test() {
    Solution s;
    vector<int> v = {1, 3, 5, 6};
    cout << s.searchInsert(v, 5);
}
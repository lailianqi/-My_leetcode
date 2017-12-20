#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int LCS(vector<int> &nums) {
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        auto it = lower_bound(result.begin(), result.end(), nums[i]);
        if (it != result.end()) {
            *it = nums[i];
        } else {
            result.push_back(nums[i]);
        }
    }
    return result.size();
}

void test() {
    vector<int> nums = {1, 4, 2, 0, 10, 18, 17};
    cout << LCS(nums) << endl;
}
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
  public:
    // 超时的解法
    int threeSumClosest(vector<int> &nums, int target) {
        int answer = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (abs(sum - target) < abs(answer - target)) {
                        answer = sum;
                    }
                }
            }
        }
        return answer;
    }
    int threeSumClosest1(vector<int> &nums, int target) {
        int answer = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int low = i + 1, high = nums.size() - 1;
            while (low < high) {
                int sum = nums[i] + nums[low] + nums[high];
                if (abs(sum - target) == 0) {
                    return sum;
                }
                if (abs(sum - target) < abs(answer - target)) {
                    answer = sum;
                }
                if (sum < target) {
                    low++;
                } else {
                    high--;
                }
            }
        }
        return answer;
    }
};
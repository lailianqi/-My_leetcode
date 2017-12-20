#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
  public:
    // 超时
    vector<vector<int> > threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > answer;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                for (int j = i + 1; j < nums.size(); j++) {
                    if (j == i + 1 || (j > i + 1 && nums[j] != nums[j - 1]))
                        for (int k = j + 1; k < nums.size(); k++) {
                            if (k == j + 1 ||
                                (k > j + 1 && nums[k] != nums[k - 1]))
                                if (nums[i] + nums[j] + nums[k] == 0) {
                                    vector<int> v;
                                    v.push_back(nums[i]);
                                    v.push_back(nums[j]);
                                    v.push_back(nums[k]);
                                    answer.push_back(v);
                                    break;
                                }
                        }
                }
            }
        }
        return answer;
    }
    //改进方案
    vector<vector<int> > threeSum1(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > answer;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                int low = i + 1, high = nums.size() - 1;
                while (low < high) {
                    if (nums[low] + nums[high] == -nums[i]) {
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[low]);
                        v.push_back(nums[high]);
                        answer.push_back(v);
                        while (low < high && nums[low] == nums[low + 1])
                            low++;
                        while (low < high && nums[high] == nums[high - 1])
                            high--;
                        low++, high--;
                    } else if (nums[low] + nums[high] < -nums[i]) {
                        low++;
                    } else {
                        high--;
                    }
                }
            }
        }
        return answer;
    }
};
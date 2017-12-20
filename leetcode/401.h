#include <string>
#include <vector>
using namespace std;
//下面是自己照着答案写的自己的解法
// leetcode的答案
// https://discuss.leetcode.com/topic/59494/3ms-java-solution-using-backtracking-and-idea-of-permutation-and-combination/2
class Solution {
  public:
    vector<string> readBinaryWatch(int num) {
        vector<int> hour = {8, 4, 2, 1}, minute = {32, 16, 8, 4, 2, 1};
        vector<string> res;
        for (int i = 0; i <= num; i++) {
            vector<int> hours = getList(hour, i);
            vector<int> minutes = getList(minute, num - i);
            for (auto hour : hours) {
                if (hour < 12) {
                    for (auto minute : minutes) {
                        if (minute < 60) {
                            res.push_back(
                                to_string(hour) + ":" +
                                (minute < 10 ? to_string(0) + to_string(minute)
                                             : to_string(minute)));
                        }
                    }
                }
            }
        }
        return res;
    }
    vector<int> getList(vector<int> &nums, int counter) {
        vector<int> res;
        generateDigit(nums, res, 0, counter, 0);
        return res;
    }
    void generateDigit(vector<int> &nums, vector<int> &res, int pos,
                       int counter, int sum) {
        if (pos + counter > nums.size()) {
            return;
        }
        if (counter == 0) {
            res.push_back(sum);
            return;
        }
        for (int i = pos; i < nums.size(); i++) {
            generateDigit(nums, res, i + 1, counter - 1, sum + nums[i]);
        }
    }
};

// sp大神的解法  给跪了
// https://discuss.leetcode.com/topic/59374/simple-python-java
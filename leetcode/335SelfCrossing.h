#include <vector>
using namespace std;
//这题根本不会
//下面是LeetCode的答案
// https://discuss.leetcode.com/topic/38014/java-oms-with-explanation/5
// https://discuss.leetcode.com/topic/38068/another-python/2?page=1
class Solution {
  public:
    bool isSelfCrossing(vector<int> &x) {
        for (int i = 3; i < x.size(); i++) {
            if (x[i] >= x[i - 2] && x[i - 1] <= x[i - 3]) {
                return true;
            } else if (i >= 4 && x[i - 1] == x[i - 3] &&
                       x[i] + x[i - 4] >= x[i - 2]) {
                return true;
            } else if (i >= 5 && x[i - 2] >= x[i - 4] &&
                       x[i] + x[i - 4] >= x[i - 2] && x[i - 1] <= x[i - 3] &&
                       x[i - 1] + x[i - 5] >= x[i - 3]) {
                return true;
            }
        }
        return false;
    }
};
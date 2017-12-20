#include <vector>
using namespace std;
//我的最佳的写法，和leetcode的最佳答案是一致的
class Solution {
  public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res;
        for (int i = 0, j = numbers.size() - 1; i < j;) {
            if (numbers[i] + numbers[j] == target) {
                res.push_back(i + 1);
                res.push_back(j + 1);
                return res;
            } else if (numbers[i] + numbers[j] < target) {
                i++;
            } else {
                j--;
            }
        }
        return res;
    }
};
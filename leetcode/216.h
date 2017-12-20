#include <vector>
using namespace std;
//自己的写法
// leetcode和这个差不多的解法
// https://discuss.leetcode.com/topic/25351/use-backtrack-c-solution-easy-to-understand
// https://discuss.leetcode.com/topic/26351/simple-and-clean-java-code-backtracking
class Solution {
  public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> answers;
        vector<int> answer;
        combinationSum3(answers, answer, 1, k, n);
        return answers;
    }
    void combinationSum3(vector<vector<int>> &answers, vector<int> &answer,
                         int start, int k, int n) {
        if (k == 0 || n < 0) {
            if (n == 0) {
                answers.push_back(answer);
            }
            return;
        }
        for (int i = start; i <= 9; i++) {
            answer.push_back(i);
            combinationSum3(answers, answer, i + 1, k - 1, n - i);
            answer.pop_back();
        }
    }
};
void test() {}
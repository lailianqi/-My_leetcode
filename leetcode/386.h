#include <vector>
using namespace std;
//这题并没有写出来
// leetcode的答案
// https://discuss.leetcode.com/topic/55184/java-o-n-time-o-1-space-iterative-solution-130ms/7
class Solution {
  public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        int curr = 1;
        for (int i = 1; i <= n; i++) {
            result.push_back(curr);
            if (curr * 10 <= n) {
                curr *= 10;
            } else if (curr % 10 != 9 && curr + 1 <= n) {
                curr++;
            } else {
                while ((curr / 10) % 10 == 9) {
                    curr /= 10;
                }
                curr = curr / 10 + 1;
            }
        }
        return result;
    }
};
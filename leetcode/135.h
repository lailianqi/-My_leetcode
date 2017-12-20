#include <vector>
using namespace std;
// Leetcode的答案
// https://discuss.leetcode.com/topic/25985/simple-o-n-java-solution-with-comments
class Solution {
  public:
    int candy(vector<int> &ratings) {
        int m = ratings.size();
        vector<int> candinate(m, 1);
        for (int i = 1; i < m; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candinate[i] = candinate[i - 1] + 1;
            }
        }
        for (int i = m - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candinate[i] = max(candinate[i + 1] + 1, candinate[i]);
            }
        }
        int sum = 0;
        for (int candy : candinate) {
            sum += candy;
        }
        return sum;
    }
};
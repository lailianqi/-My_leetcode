#include <vector>
using namespace std;
//一次性ac 这题比较简单
class Solution {
  public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration) {
        int res = 0, m = timeSeries.size();
        for (int i = 0; i < m - 1; i++) {
            if (timeSeries[i + 1] - timeSeries[i] > duration) {
                res += duration;
            } else {
                res += timeSeries[i + 1] - timeSeries[i];
            }
        }
        return res += m == 0 ? 0 : duration;
    }
};

// 自己对原有解法的改进版
// leetcode上面和这个改进相同思想的链接
// https://discuss.leetcode.com/topic/77071/o-n-java-solution-using-same-idea-of-merge-intervals/6
class Solution_1 {
  public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration) {
        int res = 0, m = timeSeries.size();
        for (int i = 0; i < m - 1; i++) {
            res += timeSeries[i + 1] - timeSeries[i] > duration
                       ? duration
                       : (timeSeries[i + 1] - timeSeries[i]);
        }
        return res += m == 0 ? 0 : duration;
    }
};
//或者写成这个
class Solution_2 {
  public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration) {
        int res = 0, m = timeSeries.size();
        for (int i = 0; i < m - 1; i++) {
            res += min(timeSeries[i + 1] - timeSeries[i], duration);
        }
        return res += m == 0 ? 0 : duration;
    }
};

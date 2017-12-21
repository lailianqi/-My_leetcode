#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
//好题 用的贪心的思想
// leetcode的答案 不算难  类似的题目写过 又有点忘了 所以第一遍没有写出来
// 一开始理解错了 例子有误导的意思 还以为找合并区间所用的的元素的最大的个数
// 其实是找不相交的集的最大数 答案=总数 - 不相交的最大的集
// https://discuss.leetcode.com/topic/65594/java-least-is-most
class Solution {
  public:
    int eraseOverlapIntervals(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(),
             [](Interval &a, Interval &b) { return a.end < b.end; });
        int end = INT_MIN, res = 0;
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i].start >= end) {
                end = intervals[i].end;
                res++;
            }
        }
        return intervals.size() - res;
    }
};
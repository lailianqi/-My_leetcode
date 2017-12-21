#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
//自己的第一种写法 成功ac
// leetcode的答案 思路是一样的
// https://discuss.leetcode.com/topic/65817/java-clear-o-n-logn-solution-based-on-treemap
// https://discuss.leetcode.com/topic/65602/c-map-solution
class Solution {
  public:
    vector<int> findRightInterval(vector<Interval> &intervals) {
        map<int, int> dir;
        vector<int> res;
        for (int i = 0; i < intervals.size(); i++) {
            dir[intervals[i].start] = i;
        }
        // sort(intervals.begin(), intervals.end(),
        //      [](Interval &a, Interval &b) { return a.start < b.start; });
        for (int i = 0; i < intervals.size(); i++) {
            auto position = dir.lower_bound(intervals[i].end);
            if (position != dir.end()) {
                res.push_back(position->second);
            } else {
                res.push_back(-1);
            }
        }
        return res;
    }
};
//上面的改进简洁版
class Solution_0 {
  public:
    vector<int> findRightInterval(vector<Interval> &intervals) {
        map<int, int> dir;
        vector<int> res;
        for (int i = 0; i < intervals.size(); i++) {
            dir[intervals[i].start] = i;
        }
        for (int i = 0; i < intervals.size(); i++) {
            auto position = dir.lower_bound(intervals[i].end);
            res.push_back(position == dir.end() ? -1 : position->second);
        }
        return res;
    }
};
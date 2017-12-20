#include <algorithm>
#include <vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
// You are here! Your runtime beats 86.95 % of cpp submissions.
class Solution {
  public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        intervals.push_back(newInterval);
        if (intervals.size() <= 1)
            return intervals;
        sort(intervals.begin(), intervals.end(),
             [](Interval a, Interval b) { return a.start < b.start; });
        vector<Interval> answers;
        int start = intervals[0].start, end = intervals[0].end;
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i].start <= end) {
                end = max(intervals[i].end, end);
            } else {
                answers.push_back(Interval(start, end));
                start = intervals[i].start;
                end = intervals[i].end;
            }
        }
        answers.push_back(Interval(start, end));
        return answers;
    }
};
//顺序插入，也可以二分插入
class Solution_0 {
  public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> answers;
        vector<Interval>::iterator it;
        for (it = intervals.begin();
             it != intervals.end() && it->start <= newInterval.start; it++) {
        }
        intervals.insert(it, newInterval);
        if (intervals.size() <= 1)
            return intervals;
        int start = intervals[0].start, end = intervals[0].end;
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i].start <= end) {
                end = max(intervals[i].end, end);
            } else {
                answers.push_back(Interval(start, end));
                start = intervals[i].start;
                end = intervals[i].end;
            }
        }
        answers.push_back(Interval(start, end));
        return answers;
    }
};
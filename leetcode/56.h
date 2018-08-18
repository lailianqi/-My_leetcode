#include <algorithm>
#include <vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
    bool operator<=(const Interval &b) { return start <= b.start; }
};

class Solution {
  public:
    vector<Interval> merge(vector<Interval> &intervals) {
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

class Solution_0 {
  public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.size() == 0) {
            return {};
        }
        vector<Interval> res;
        sort(intervals.begin(), intervals.end(),
             [](Interval &a, Interval &b) { return a.start < b.start; });//Strict Weak Ordering
        int m = intervals.size(), start = intervals[0].start,
            end = intervals[0].end;
        for (int i = 0; i < m; i++) {
            if (intervals[i].start <= end) {
                end = max(end, intervals[i].end);
            } else {
                res.push_back(Interval(start, end));
                start = intervals[i].start, end = intervals[i].end;
            }
        }
        res.push_back(Interval(start, end));
        return res;
    }
};
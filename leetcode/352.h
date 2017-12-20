#include <vector>
#include <algorithm>
using namespace std;
//没有写出来
// leetcode的答案
// https://discuss.leetcode.com/topic/46904/very-concise-c-solution
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class SummaryRanges {
  public:
    /** Initialize your data structure here. */
    SummaryRanges() {}

    void addNum(int val) {
        auto Cmp = [](Interval a, Interval b) { return a.start < b.start; };
        auto it =
            lower_bound(result.begin(), result.end(), Interval(val, val), Cmp);
        int start = val, end = val;
        if (it != result.begin() && (it - 1)->end + 1 >= val) {
            it--;
        }
        while (it != result.end() && val + 1 >= it->start &&
               val - 1 <= it->end) {
            start = min(start, it->start);
            end = max(end, it->end);
            it = result.erase(it);
        }
        result.insert(it, Interval(start, end));
    }

    vector<Interval> getIntervals() { return result; }

  private:
    vector<Interval> result;
};

// leetcode的答案
// treeMap写的
// https://discuss.leetcode.com/topic/46887/java-solution-using-treemap-real-o-logn-per-adding
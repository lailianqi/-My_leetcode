#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

// class Interval {
//   public:
//     Interval(int start, int end) {
//         this->start = start;
//         this->end = end;
//     }
//     int start, end;
//     bool operator<(const Interval &i) {
//         return this->start != i.start ? this->start < i.start
//                                       : this->end < i.end;
//     }
// };

// 自己的第一种解法  成功ac  这道题是好题
// leetcode类似的答案
// https://leetcode.com/problems/my-calendar-i/discuss/109462/Java-8-liner-TreeMap
// https://leetcode.com/problems/my-calendar-i/discuss/109475/JavaC++-Clean-Code-with-Explanation
class MyCalendar {
  public:
    MyCalendar() {}

    bool book(int start, int end) {
        pair<int, int> interval(start, end);
        auto it = dir.lower_bound(interval);
        if (it != dir.end() && it->first < end) {
            return false;
        }
        if (it != dir.begin() && (--it)->second > start) {
            return false;
        }
        dir.insert(interval);
        return true;
    }

  private:
    set<pair<int, int>> dir;
};

//第二种方案 来自LeetCode 使用的map
// https://leetcode.com/problems/my-calendar-i/discuss/109462/Java-8-liner-TreeMap
// https://leetcode.com/problems/my-calendar-i/discuss/109475/JavaC++-Clean-Code-with-ExplanationF
class MyCalendar_0 {
  public:
    MyCalendar_0() {}

    bool book(int start, int end) {
        auto it = dir.lower_bound(start);
        if (it != dir.end() && it->first < end) {
            return false;
        }
        if (it != dir.begin() && (--it)->second > start) {
            return false;
        }
        dir[start] = end;
        return true;
    }

  private:
    map<int, int> dir;
};

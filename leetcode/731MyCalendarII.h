#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;

// 这题没写出来 直接看的LeetCode的答案 下面是来自LeetCode的答案
// https://leetcode.com/problems/my-calendar-ii/discuss/109519/JavaC++-Clean-Code-with-Explanation?page=1
// MyCalendarI 的解法
class MyCalendar {
    vector<pair<int, int>> books;

  public:
    bool book(int start, int end) {
        for (pair<int, int> p : books)
            if (max(p.first, start) < min(end, p.second))
                return false;
        books.push_back({start, end});
        return true;
    }
};
// MyCalendarII 的解法
class MyCalendarTwo {
  public:
    MyCalendarTwo() {}

    bool book(int start, int end) {
        MyCalendar overlaps;
        for (auto &p : books) {
            if (max(p.first, start) < min(end, p.second)) {
                pair<int, int> overlap =
                    getOverlap(p.first, p.second, start, end);
                if (!overlaps.book(overlap.first, overlap.second)) {
                    return false;
                }
            }
        }
        books.push_back({start, end});
        return true;
    }

  private:
    vector<pair<int, int>> books;
    pair<int, int> getOverlap(int s0, int e0, int s1, int e1) {
        return {max(s0, s1), min(e0, e1)};
    }
};

// 最牛逼的方法之一
// https://leetcode.com/problems/my-calendar-ii/discuss/109522/Simplified-winner's-solution
class MyCalendarTwo_0 {
  public:
    MyCalendarTwo_0() {}

    bool book(int start, int end) {
        int res = 0;
        dir[start]++, dir[end]--;
        for (auto &it : dir) {
            res += it.second;
            if (res == 3) {
                dir[start]--;
                dir[end]++;
                return false;
            }
        }
        return true;
    }

  private:
    map<int, int> dir;
};

// 来自LeetCode的第三种方法
// https://leetcode.com/problems/my-calendar-ii/discuss/109530/N2-Python-Short-and-Elegant
class MyCalendarTwo_1 {
  public:
    MyCalendarTwo_1() {}

    bool book(int start, int end) {
        for (auto &p : overlaps) {
            if (max(start, p.first) < min(end, p.second)) {
                return false;
            }
        }
        for (auto &p : calendar) {
            if (max(start, p.first) < min(end, p.second)) {
                overlaps.emplace_back(max(start, p.first), min(end, p.second));
            }
        }
        calendar.emplace_back(start, end);
        return true;
    }

  private:
    vector<pair<int, int>> overlaps;
    vector<pair<int, int>> calendar;
};
#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;
// 这题直接看的答案 因为题目太长 没耐心看下去
// 其实这道题在困难题中还是非常的简单的
// 来自LeetCode的答案
// 最普通且基本上是最简单的做法
// https://leetcode.com/problems/falling-squares/discuss/108766/Easy-Understood-O(n2)-Solution-with-explanation
class Solution {
  public:
    vector<int> fallingSquares(vector<pair<int, int>> &positions) {
        vector<Interval> intervals;
        vector<int> res;
        int maxHeight = 0;
        for (int i = 0; i < positions.size(); i++) {
            Interval cur =
                Interval(positions[i].first,
                         positions[i].first + positions[i].second - 1,
                         positions[i].second);
            maxHeight = max(maxHeight, getHeight(intervals, cur));
            res.push_back(maxHeight);
        }
        return res;
    }

  private:
    class Interval {
      public:
        int start, end, height;
        Interval(int start, int end, int height) {
            this->start = start;
            this->end = end;
            this->height = height;
        }
    };
    int getHeight(vector<Interval> &intervals, Interval &cur) {
        int preMaxHeight = 0;
        for (auto element : intervals) {
            if (element.end < cur.start || element.start > cur.end) {
                continue;
            }
            preMaxHeight = max(preMaxHeight, element.height);
        }
        cur.height += preMaxHeight;
        intervals.push_back(cur);
        return cur.height;
    }
};

// 类似218题 天际线问题
// 下面的思路我已经看懂了 感觉有点麻烦
// https://leetcode.com/problems/falling-squares/discuss/108769/C++-O(nlogn)
class Solution_0 {
  public:
    vector<int> fallingSquares(vector<pair<int, int>> &positions) {
        map<pair<int, int>, int> mp;
        mp[{0, 1000000000}] = 0;
        vector<int> res;
        int maxValue = 0;
        for (auto &element : positions) {
            vector<vector<int>> toAdd;
            int len = element.second, a = element.first,
                b = element.first + element.second, h = 0;
            auto it = mp.upper_bound({a, a});
            if (it != mp.begin() && (--it)->first.second <= a)
                ++it;
            while (it != mp.end() && it->first.first < b) {
                if (a > it->first.first) {
                    toAdd.push_back({it->first.first, a, it->second});
                }
                if (b < it->first.second) {
                    toAdd.push_back({b, it->first.second, it->second});
                }
                h = max(h, it->second);
                it = mp.erase(it);
            }
            mp[{a, b}] = h + len;
            for (auto &t : toAdd)
                mp[{t[0], t[1]}] = t[2];
            maxValue = max(maxValue, h + len);
            res.push_back(maxValue);
        }
        return res;
    }
};

// 另外的一种解法
// https://leetcode.com/problems/falling-squares/discuss/108783/c++-map-based-short-solution
class Solution_1 {
  public:
    vector<int> fallingSquares(vector<pair<int, int>> &positions) {
        map<int, int> mp = {{0, 0}, {INT_MAX, 0}};
        vector<int> res;
        int cur = 0;
        for (auto &element : positions) {
            int left = element.first, right = element.first + element.second,
                h = element.second, maxH = 0;
            auto ptri = mp.upper_bound(left), ptrj = mp.lower_bound(right);
            int tmp = ptrj->first == right ? ptrj->second : (--ptrj)++->second;
            for (auto ptr = --ptri; ptr != ptrj; ptr++) {
                maxH = max(maxH, ptr->second);
            }
            mp.erase(++ptri, ptrj);
            mp[left] = h + maxH;
            mp[right] = tmp;
            cur = max(cur, mp[left]);
            res.push_back(cur);
        }
        return res;
    }
};
// python的解法 非常的牛逼
// https://leetcode.com/problems/falling-squares/discuss/108764/Easy-and-Concise-Python-Solution-(97)?page=2
// def fallingSquares(self, positions):
//         height = [0]
//         pos = [0]
//         res = []
//         max_h = 0
//         for left, side in positions:
//             i = bisect.bisect_right(pos, left)
//             j = bisect.bisect_left(pos, left + side)
//             high = max(height[i - 1:j] or [0]) + side
//             pos[i:j] = [left, left + side]
//             height[i:j] = [high, height[j - 1]]
//             max_h = max(max_h, high)
//             res.append(max_h)
//         return res
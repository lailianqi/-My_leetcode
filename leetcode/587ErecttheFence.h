#include <set>
#include <unordered_set>
#include <vector>
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};
// 这题不可能写出来 这个算法我根本不知道
// 来自LeetCode的答案
// https://discuss.leetcode.com/topic/89323/java-solution-convex-hull-algorithm-gift-wrapping-aka-jarvis-march
// https://en.wikipedia.org/wiki/Gift_wrapping_algorithm
// https://www.cnblogs.com/Booble/archive/2011/02/28/1967179.html

//官方的题解
class Solution {
  private:
    struct comp {
        bool operator()(Point a, Point b) {
            return a.x == b.x ? a.y < b.y : a.x < b.x;
        }
    };

  public:
    vector<Point> outerTrees(vector<Point> &points) {
        set<Point, comp> hull;
        if (points.size() < 4) {
            for (Point p : points)
                hull.insert(p);
            return vector<Point>(hull.begin(), hull.end());
        }
        int left_most = 0;
        for (int i = 0; i < points.size(); i++)
            if (points[i].x < points[left_most].x)
                left_most = i;
        int p = left_most;
        do {
            int q = (p + 1) % points.size();
            for (int i = 0; i < points.size(); i++) {
                //>0 应该是顺时针 <0是逆时针 //这里的orientation反了 变成了qrXpq
                if (orientation(points[p], points[i], points[q]) > 0) {
                    q = i;
                }
            }
            for (int i = 0; i < points.size(); i++) {
                if (i != p && i != q &&
                    orientation(points[p], points[i], points[q]) == 0 &&
                    inBetween(points[p], points[i], points[q])) {
                    hull.insert(points[i]);
                }
            }
            hull.insert(points[q]);
            p = q;
        } while (p != left_most);
        return vector<Point>(hull.begin(), hull.end());
    }
    // 卧槽 这个公式反了 <0  q才是满足条件的
    int orientation(Point p, Point q, Point r) {
        return (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    }
    bool inBetween(Point p, Point i, Point q) {
        bool a = (i.x >= p.x && i.x <= q.x) || (i.x <= p.x && i.x >= q.x);
        bool b = (i.y >= p.y && i.y <= q.y) || (i.y <= p.y && i.y >= q.y);
        return a && b;
    }
};
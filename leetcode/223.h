#include <cmath>
#include <algorithm>
using namespace std;
//自己写的方法 leetcode上最快的方案是12ms，这个方案到达了16ms
class Solution {
  public:
    class Point {
      public:
        Point(int x, int y) : x(x), y(y) {}
        int x;
        int y;
    };
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        vector<int> x(4, 0), y(4, 0);
        Point point1(A, B), point2(C, D), point3(E, F), point4(G, H);
        if (!isIntersectRantangle(point1, point2, point3, point4)) {
            return getArea(point1, point2) + getArea(point3, point4);
        }
        x[0] = point1.x, x[1] = point2.x, x[2] = point3.x, x[3] = point4.x;
        y[0] = point1.y, y[1] = point2.y, y[2] = point3.y, y[3] = point4.y;
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        return getArea(point1, point2) + getArea(point3, point4) -
               abs(x[1] - x[2]) * abs(y[1] - y[2]);
    }
    //判断矩形是否相交
    bool isIntersectRantangle(Point a1, Point b1, Point a2, Point b2) {
        return min(b1.x, b2.x) >= max(a1.x, a2.x) &&
               min(b1.y, b2.y) >= max(a1.y, a2.y);
    }
    int getArea(Point rec1, Point rec2) {
        return abs(rec1.x - rec2.x) * abs(rec1.y - rec2.y);
    }
};
// leetcode的解法
// 看了后觉得是我的方法的扩展
// https://discuss.leetcode.com/topic/17705/just-another-short-way/4
class Solution_0 {
  public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int x = min(G, C) > max(E, A) ? (min(G, C) - max(E, A)) : 0;
        int y = min(H, D) > max(B, F) ? (min(H, D) - max(B, F)) : 0;
        return (D - B) * (C - A) + (G - E) * (H - F) - x * y;
    }
};

void test() {
    Solution s;
    s.computeArea(0, 0, 0, 0, -1, -1, 1, 1);
}
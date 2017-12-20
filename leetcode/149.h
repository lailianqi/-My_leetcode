#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};
// https://discuss.leetcode.com/topic/2979/a-java-solution-with-notes/12?page=1
// leetcode的答案
//这个答案非常的具有疑问，有问题。
class Solution {
  public:
    int maxPoints(vector<Point> &points) {
        if (points.size() <= 2)
            return points.size();
        map<int, map<int, int>> map;
        int result = 0;
        for (unsigned int i = 0; i < points.size(); i++) {
            map.clear();
            int localmax = 0, overlap = 0;
            for (unsigned int j = i + 1; j < points.size(); j++) {
                int x = points[j].x - points[i].x;
                int y = points[j].y - points[i].y;
                if (x == 0 && y == 0) {
                    overlap++;
                    continue;
                }
                int gcd = generateGCD(x, y);
                if (gcd != 0) {
                    x /= gcd;
                    y /= gcd;
                }
                int curr = ++map[x][y];
                localmax = max(curr, localmax);
            }
            result = max(result, localmax + overlap + 1);
        }
        return result;
    }

  private:
    int generateGCD(int a, int b) {
        if (b == 0)
            return a;
        return generateGCD(b, a % b);
    }
};
//这个才是正确的答案
// leetCode的答案
// https://discuss.leetcode.com/topic/2979/a-java-solution-with-notes/38?page=2
class Solution_0 {
  public:
    int maxPoints(vector<Point> &points) {
        int m = points.size(), result = 0;
        if (m <= 2)
            return m;
        map<string, int> maps;
        for (int i = 0; i < m - 1; i++) {
            maps.clear();
            int overlap = 0, maxSum = 0;
            for (int j = i + 1; j < m; j++) {
                int x = points[j].x - points[i].x;
                int y = points[j].y - points[i].y;
                if (x == 0 && y == 0) {
                    overlap++;
                    continue;
                }
                int gcd = generateGcd(x, y); // gcd will never be zero.
                x /= gcd;
                y /= gcd;
                string key = to_string(x) + ":" + to_string(y);
                maps[key]++;
                maxSum = max(maxSum, maps[key]);
            }
            result = max(result, maxSum + overlap + 1);
        }
        return result;
    }

  private:
    int generateGcd(int a, int b) {
        if (b == 0)
            return a;
        return generateGcd(b, a % b);
    }
};

void test() {
    Solution s;
    Point p1(0, 0);
    Point p2(1, 1);
    Point p3(1, 2);
    Point p4(2, 2);
    vector<Point> points;
    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);
    points.push_back(p4);
    cout << s.maxPoints(points) << endl;
}
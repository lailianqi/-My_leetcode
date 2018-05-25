#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
// https://leetcode.com/problems/largest-triangle-area/discuss/122711/C++JavaPython-Solution-with-Explanation-and-Prove
// https://leetcode.com/problems/largest-triangle-area/discuss/124010/Simple-Java-Easy-Understand
class Solution {
  public:
    double largestTriangleArea(vector<vector<int>> &points) {
        int m = points.size();
        double res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                for (int k = j + 1; k < m; k++) {
                    res = max(res, area_cal(points[i], points[j], points[k]));
                }
            }
        }
        return res;
    }
    double area_cal(vector<int> &a, vector<int> &b, vector<int> &c) {
        return abs(a[0] * (b[1] - c[1]) + b[0] * (c[1] - a[1]) +
                   c[0] * (a[1] - b[1]))/2.0;
    }
};
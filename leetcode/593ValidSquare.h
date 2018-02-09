#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;
// 这题嫌麻烦 直接看的官方的题解
class Solution {
  public:
    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3,
                     vector<int> &p4) {
        vector<vector<int>> points = {p1, p2, p3, p4};
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        return dist(points[0], points[1]) != 0 &&
               dist(points[0], points[1]) == dist(points[1], points[3]) &&
               dist(points[1], points[3]) == dist(points[3], points[2]) &&
               dist(points[3], points[2]) == dist(points[2], points[0]) &&
               dist(points[0], points[3]) == dist(points[1], points[2]);
    }
    int dist(vector<int> &a, vector<int> &b) {
        return (a[1] - b[1]) * (a[1] - b[1]) + (a[0] - b[0]) * (a[0] - b[0]);
    }
};

// discuss的答案简直碉堡了 答案来自LeetCode 比官方的题解牛逼多了
// https://discuss.leetcode.com/topic/89985/c-3-lines-unordered_set
// https://discuss.leetcode.com/topic/90079/4-liner-java/7
class Solution_0 {
  public:
    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3,
                     vector<int> &p4) {
        unordered_set<int> s({dist(p1, p2), dist(p1, p3), dist(p1, p4),
                              dist(p2, p3), dist(p2, p4), dist(p3, p4)});
        return !s.count(0) && s.size() == 2;
    }
    int dist(vector<int> &a, vector<int> &b) {
        return (a[1] - b[1]) * (a[1] - b[1]) + (a[0] - b[0]) * (a[0] - b[0]);
    }
};
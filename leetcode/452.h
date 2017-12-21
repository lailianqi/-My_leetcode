#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//自己的第一种写法 完美ac 这题写的挺久 主要是在调试的时候
class Solution {
  public:
    int findMinArrowShots(vector<pair<int, int>> &points) {
        sort(points.begin(), points.end(),
             [](pair<int, int> &a, pair<int, int> &b) {
                 if (a.first != b.first) {
                     return a.first < b.first;
                 } else {
                     return a.second < b.second;
                 }
             });
        // for (int i = 0; i < points.size(); i++) {
        //     cout << points[i].first << " " << points[i].second << endl;
        // }
        int end = INT_MIN, res = 0;
        for (int i = 0; i < points.size(); i++) {
            if (i == 0 || points[i].first > end) {
                res++;
                end = points[i].second;
            } else {
                end = min(end, points[i].second);
            }
        }
        return res;
    }
};

void test() {
    Solution s;
    vector<pair<int, int>> nums = {{3, 9}, {7, 12}, {3, 8}, {6, 8}, {9, 10},
                                   {2, 9}, {0, 9},  {3, 9}, {0, 6}, {2, 8}};
    s.findMinArrowShots(nums);
}
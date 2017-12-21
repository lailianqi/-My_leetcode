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
// leetcode的答案 思路更加清晰的解法 小作修改
// https://discuss.leetcode.com/topic/73981/share-my-explained-greedy-solution-as-the-highest-voted-java-solution-right-now-is-not-ideal/3
class Solution_0 {
  public:
    int findMinArrowShots(vector<pair<int, int>> &points) {
        sort(points.begin(), points.end(),
             [](pair<int, int> &a, pair<int, int> &b) {
                 return a.second < b.second;
             });
        int end = 0, res = 0;
        for (int i = 0; i < points.size(); i++) {
            if (i == 0 || points[i].first > end) {
                end = points[i].second;
                res++;
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
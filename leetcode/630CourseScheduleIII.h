#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
// 自己的贪心的解法错了 下面是错误的解法
// 所以这题并没有自己做出来

class Solution {
  public:
    int scheduleCourse(vector<vector<int>> &courses) {
        sort(courses.begin(), courses.end(),
             [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });
        int end = courses[0][0], res = 1;
        for (int i = 1; i < courses.size();) {
            if (end + courses[i][0] <= courses[i][1]) {
                end = end + courses[i][0];
                res++;
            } else {
                i++;
            }
        }
        return res;
    }
};
// 来自LeetCode的答案
// https://www.cnblogs.com/grandyang/p/7126289.html
// https://leetcode.com/problems/course-schedule-iii/discuss/104845/Short-Java-code-using-PriorityQueue
class Solution_0 {
  public:
    int scheduleCourse(vector<vector<int>> &courses) {
        sort(courses.begin(), courses.end(),
             [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });
        priority_queue<int> maxHeap;
        int time = 0;
        for (int i = 0; i < courses.size(); i++) {
            time += courses[i][0];
            maxHeap.push(courses[i][0]);
            //因为未加入新的元素之前肯定是满足总时间小于截止时间的
            //所以加入新的元素不满足截止时间后去除时间最长的元素还是满足截止时间需求的
            if (time > courses[i][1]) {
                time -= maxHeap.top();
                maxHeap.pop();
            }
        }
        return maxHeap.size();
    }
};
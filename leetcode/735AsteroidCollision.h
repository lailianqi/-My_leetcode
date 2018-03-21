#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// 自己的第一种解法 成功ac 这题是好题 并且完全按照自己的想法写出了答案
// 但是这种解法时间效率不高
class Solution {
  public:
    vector<int> asteroidCollision(vector<int> &asteroids) {
        int m = asteroids.size();
        return helper(asteroids, 0, m);
    }
    vector<int> helper(vector<int> &asteroids, int left, int right) {
        if (left == right - 1) {
            return {asteroids[left]};
        }
        int middle = (left + right) / 2;
        vector<int> leftPart = helper(asteroids, left, middle),
                    rightPart = helper(asteroids, middle, right), res;
        int m = leftPart.size(), n = rightPart.size();
        int leftIndex = m - 1, rightIndex = 0;
        while (leftIndex >= 0 && rightIndex < n && leftPart[leftIndex] > 0 &&
               rightPart[rightIndex] < 0) {
            if (abs(leftPart[leftIndex]) > abs(rightPart[rightIndex])) {
                rightIndex++;
            } else if (abs(leftPart[leftIndex]) < abs(rightPart[rightIndex])) {
                leftIndex--;
            } else {
                rightIndex++, leftIndex--;
            }
        }
        for (int i = 0; i <= leftIndex; i++) {
            res.push_back(leftPart[i]);
        }
        for (int i = rightIndex; i < n; i++) {
            res.push_back(rightPart[i]);
        }
        return res;
    }
};

// 来自LeetCode的解法 用了stack的解法
// https://leetcode.com/problems/asteroid-collision/discuss/109694/JavaC++-Clean-Code

class Solution_0 {
  public:
    vector<int> asteroidCollision(vector<int> &asteroids) {
        vector<int> stack;
        int m = asteroids.size();
        for (int i = 0; i < m; i++) {
            if (asteroids[i] > 0 || stack.empty() || stack.back() < 0) {
                stack.push_back(asteroids[i]);
            } else if (stack.back() <= -asteroids[i]) {
                if (stack.back() < -asteroids[i]) {
                    i--;
                }
                stack.pop_back();
            }
        }
        return stack;
    }
};

// 上面的改写版
// https://leetcode.com/problems/asteroid-collision/discuss/109694/JavaC++-Clean-Code
class Solution_1 {
  public:
    vector<int> asteroidCollision(vector<int> &asteroids) {
        vector<int> stack;
        int m = asteroids.size();
        for (int i = 0; i < m; i++) {
            while (!stack.empty() && stack.back() > 0 &&
                   stack.back() < -asteroids[i]) {
                stack.pop_back();
            }
            if (stack.empty() || stack.back() < 0 || asteroids[i] > 0) {
                stack.push_back(asteroids[i]);
            }
            if (asteroids[i] < 0 && stack.back() == -asteroids[i]) {
                stack.pop_back();
            }
        }
        return stack;
    }
};
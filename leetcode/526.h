#include <vector>
using namespace std;
// 自己的第一种方案，一次ac，感觉程序的运行效率太低
// leetcode上相同思想和写法的答案
// https://discuss.leetcode.com/topic/79916/java-solution-backtracking
class Solution {
  public:
    int countArrangement(int N) {
        int res = 0;
        vector<int> visit(N + 1, 0);
        helper(visit, N, 1, res);
        return res;
    }
    void helper(vector<int> &visit, int N, int deep, int &res) {
        if (deep > N) {
            res++;
            return;
        }
        for (int i = 1; i <= N; i++) {
            if (visit[i] == 0 && (i % deep == 0 || deep % i == 0)) {
                visit[i] = 1;
                helper(visit, N, deep + 1, res);
                visit[i] = 0;
            }
        }
    }
};
//从后往前快了挺多  就是先安排后面的位置 而不是从前面开始占位置
class Solution_0 {
  public:
    int countArrangement(int N) {
        int res = 0;
        vector<int> visit(N + 1, 0);
        helper(visit, N, 1, res);
        return res;
    }
    void helper(vector<int> &visit, int N, int deep, int &res) {
        if (deep > N) {
            res++;
            return;
        }
        for (int i = N; i >= 1; i--) {
            if (visit[i] == 0 && (i % deep == 0 || deep % i == 0)) {
                visit[i] = 1;
                helper(visit, N, deep + 1, res);
                visit[i] = 0;
            }
        }
    }
};

//第三种写法 来自leetcode的答案 最快的方法
// https://discuss.leetcode.com/topic/79921/my-c-elegant-solution-with-back-tracking
class Solution_1 {
  public:
    int countArrangement(int N) {
        vector<int> nums(N, 0);
        for (int i = 0; i < N; i++) {
            nums[i] = i + 1;
        }
        return helper(nums, N);
    }
    int helper(vector<int> &nums, int n) {
        if (n <= 0) {
            return 1;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] % n == 0 || n % nums[i] == 0) {
                swap(nums[i], nums[n - 1]);
                res += helper(nums, n - 1);
                swap(nums[i], nums[n - 1]);
            }
        }
        return res;
    }
};
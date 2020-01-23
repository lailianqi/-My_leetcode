#include <vector>
using namespace std;
//自己的答案 Time Limit Exceeded
class Solution {
  public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int m = gas.size();
        int gasTankAmount = 0;
        for (int i = 0; i < m; i++) {
            int j = i;
            gasTankAmount = 0;
            while (true) {
                gasTankAmount += gas[j] - cost[j];
                if (gasTankAmount < 0) {
                    break;
                }
                j = (j + 1) % m;
                if (j == i) {
                    return i;
                }
            }
        }
        return -1;
    }
};
//最大子序列的解法
// http://www.cnblogs.com/felixfang/p/3814463.html
class Solution_0 {
  public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int m = gas.size();
        int sum = 0, total = 0, start = 0;
        for (int i = 0; i < m; i++) {
            total += gas[i] - cost[i];
            if (sum < 0) {
                sum = gas[i] - cost[i];
                start = i;
            } else {
                sum += gas[i] - cost[i];
            }
        }
        return total >= 0 ? start : -1;
    }
};
/*
I have thought for a long time and got two ideas:
If car starts at A and can not reach B. Any station between A and B
can not reach B.(B is the first station that A can not reach.)
If the total number of gas is bigger than the total number of cost. There must
be a solution. (Should I prove them?)
*/
// https://discuss.leetcode.com/topic/1344/share-some-of-my-ideas
class Solution_1 {
  public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int m = gas.size();
        int tank = 0, total = 0, start = 0;
        for (int i = 0; i < m; i++) {
            total += gas[i] - cost[i];
            tank += gas[i] - cost[i];
            if (tank < 0) {
                tank = 0;
                start = i + 1;
            }
        }
        return total >= 0 ? start : -1;
    }
};
// https://discuss.leetcode.com/topic/5088/my-ac-is-o-1-space-o-n-running-time-solution-does-anybody-have-posted-this-solution
class Solution_2 {
  public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {

        int start = gas.size() - 1;
        int end = 0;
        int sum = gas[start] - cost[start];
        while (start > end) {
            if (sum >= 0) {
                sum += gas[end] - cost[end];
                ++end;
            } else {
                --start;
                sum += gas[start] - cost[start];
            }
        }
        return sum >= 0 ? start : -1;
    }
};
void test() {
    Solution s;
    vector<int> gas = {1, 2};
    vector<int> cost = {2, 1};
    s.canCompleteCircuit(gas, cost);
}

// 二刷---------------------
class Solution {
  public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int m = gas.size();
        int res = 0, remain = gas[0] - cost[0];
        int sum = remain;
        for (int i = 1; i < m; i++) {
            if (remain < 0) {
                res = i;
                remain = gas[i] - cost[i];
            } else {
                remain += gas[i] - cost[i];
            }
            sum += gas[i] - cost[i];
        }
        return sum < 0 ? -1 : res;
    }
};
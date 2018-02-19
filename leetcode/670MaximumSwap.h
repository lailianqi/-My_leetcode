#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// 我的第一种思路 没有成功ac 当做反思
class Solution {
  public:
    int maximumSwap(int num) {
        string numstring = to_string(num);
        char maxValue = '0';
        int index = 0;
        for (int i = 0; i < numstring.size(); i++) {
            if (numstring[i] >= maxValue) {
                index = i;
                maxValue = numstring[i];
            }
        }
        for (int i = 0; i < index; i++) {
            if (numstring[i] < numstring[index]) {
                swap(numstring[i], numstring[index]);
                break;
            }
        }
        return stoi(numstring);
    }
};

// LeetCode的第一种解法
// https://leetcode.com/problems/maximum-swap/discuss/107084/C++-3ms-O(n)-time-O(n)-space-DP-solution
class Solution_0 {
  public:
    int maximumSwap(int num) {
        string numString = to_string(num);
        int m = numString.size();
        vector<int> dpPosition(m, -1);
        int curMaxPos = m - 1;
        for (int i = m - 1; i >= 0; i--) {
            if (numString[i] > numString[curMaxPos]) {
                curMaxPos = i;
            }
            dpPosition[i] = curMaxPos;
        }
        for (int i = 0; i < m; i++) {
            if (numString[i] != numString[dpPosition[i]]) {
                swap(numString[i], numString[dpPosition[i]]);
                break;
            }
        }
        return stoi(numString);
    }
};

// LeetCode的解法
// 这种解法 利用了抽屉原理 得票数是最多的
// https://leetcode.com/problems/maximum-swap/discuss/107068/Java-simple-solution-O(n)-time
class Solution_1 {
  public:
    int maximumSwap(int num) {
        string numString = to_string(num);
        int m = numString.size();
        vector<int> buckets(10, 0);
        for (int i = 0; i < numString.length(); i++) {
            buckets[numString[i] - '0'] = i;
        }
        for (int i = 0; i < numString.size(); i++) {
            for (int k = 9; k > numString[i] - '0'; k--) {
                if (buckets[k] > i) {
                    swap(numString[buckets[k]], numString[i]);
                    return stoi(numString);
                }
            }
        }
        return num;
    }
};

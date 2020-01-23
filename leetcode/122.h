#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

/*
Say you have an array for which the ith element is the price of a given stock on
day i.

Design an algorithm to find the maximum profit. You may complete as many
transactions as you like (ie, buy one and sell one share of the stock multiple
times). However, you may not engage in multiple transactions at the same time
(ie, you must sell the stock before you buy again).
*/

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int result = 0;
        for (int i = 1; i < prices.size(); i++) {
            int temp = prices[i] - prices[i - 1];
            if (temp > 0) {
                result += temp;
            }
        }
        return result;
    }
};
//简写的方案
class Solution_0 {
  public:
    int maxProfit(vector<int> &prices) {
        int result = 0;
        for (int i = 1; i < prices.size(); i++) {
            result += max(0, prices[i] - prices[i - 1]);
        }
        return result;
    }
};

// 二刷----------------
class Solution_2 {
  public:
    int maxProfit(vector<int> &prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            res += max(prices[i] - prices[i - 1], 0);
        }
        return res;
    }
};
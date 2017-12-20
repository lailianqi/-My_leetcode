#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*
Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5
max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than
buying price)
Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0
In this case, no transaction is done, i.e. max profit = 0.
*/

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0)
            return 0;
        int result = 0;
        int minNum = prices[0];
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minNum) {
                minNum = prices[i];
            } else {
                result = max(result, prices[i] - minNum);
            }
        }
        return result;
    }
};
//稍微改进的写法
class Solution_0 {
  public:
    int maxProfit(vector<int> &prices) {
        int result = 0;
        int minNum = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            minNum = min(minNum, prices[i]);
            result = max(result, prices[i] - minNum);
        }
        return result;
    }
};

// Leetcode的解法
/*
The logic to solve this problem is same as "max subarray problem" using Kadane's
Algorithm. Since no body has mentioned this so far, I thought it's a good thing
for everybody to know.

All the straight forward solution should work, but if the interviewer twists the
question slightly by giving the difference array of prices, Ex: for {1, 7, 4,
11}, if he gives {0, 6, -3, 7}, you might end up being confused.

Here, the logic is to calculate the difference (maxCur += prices[i] -
prices[i-1]) of the original array, and find a contiguous subarray giving
maximum profit. If the difference falls below 0, reset it to zero.
*/
class Solution_1 {
  public:
    int maxProfit(vector<int> &prices) {
        int maxCur = 0, maxSoFar = 0;
        for (int i = 1; i < prices.size(); i++) {
            maxCur = max(0, maxCur += prices[i] - prices[i - 1]);
            maxSoFar = max(maxCur, maxSoFar);
        }
        return maxSoFar;
    }
};
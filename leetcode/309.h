#include <vector>
#include <climits>
using namespace std;
//这题真得非常的难，在理解的层面
// leetcode的答案突破了这个层面
//教会了计算理论的东西
// https://discuss.leetcode.com/topic/30680/share-my-dp-solution-by-state-machine-thinking?page=1
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1)
            return 0;
        vector<int> rest(prices.size(), 0);
        vector<int> buy(prices.size(), 0);
        vector<int> sell(prices.size(), 0);
        rest[0] = 0;
        buy[0] = -prices[0];
        sell[0] = INT_MIN;
        for (int i = 1; i < prices.size(); i++) {
            rest[i] = max(rest[i - 1], sell[i - 1]);
            buy[i] = max(rest[i - 1] - prices[i], buy[i - 1]);
            sell[i] = buy[i - 1] + prices[i];
        }
        return max(rest[prices.size() - 1], sell[prices.size() - 1]);
    }
};
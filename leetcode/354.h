#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
/*
Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you
can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
*/
//这道题的难度是困难 但是自己的第一次提交就通过 牛逼
//不过这种方案速度不够
class Solution {
  public:
    int maxEnvelopes(vector<pair<int, int>> &envelopes) {
        int m = envelopes.size(), result = 0;
        sort(envelopes.begin(), envelopes.end());
        vector<int> dp(m + 1, 0);
        for (int i = 1; i <= m; i++) {
            dp[i] = 1;
            for (int j = 1; j < i; j++) {
                if (envelopes[i - 1].first > envelopes[j - 1].first &&
                    envelopes[i - 1].second > envelopes[j - 1].second) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            result = max(result, dp[i]);
        }
        return result;
    }
};
// leetcode的答案 其实我已经差不多想到了
// https://discuss.leetcode.com/topic/47469/java-nlogn-solution-with-explanation/2?page=1
class Solution_0 {
  public:
    static bool cmp_first(const pair<int, int> &i, const pair<int, int> &j) {
        if (i.first == j.first)
            return i.second > j.second;
        return i.first < j.first;
    }
    int maxEnvelopes(vector<pair<int, int>> &envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp_first);
        vector<int> dp;
        for (int i = 0; i < envelopes.size(); ++i) {
            auto itr = lower_bound(dp.begin(), dp.end(), envelopes[i].second);
            if (itr == dp.end()) {
                dp.push_back(envelopes[i].second);
                //   cout << envelopes[i].second << " ";
            } else {
                *itr = envelopes[i].second;
                //   cout << "else " << envelopes[i].second;
            }
        }
        return dp.size();
    }
};
void test() {
    Solution_0 s;
    vector<pair<int, int>> envelopes = {{2, 2}, {5, 4}, {6, 7}, {6, 3}};
    s.maxEnvelopes(envelopes);
}
#include <queue>
#include <string>
#include <vector>
using namespace std;
// 这题虽然简单 但是没有想出来
// 来自LeetCode的答案 贪心的思想
// https://leetcode.com/problems/dota2-senate/discuss/105858/JavaC++-Very-simple-greedy-solution-with-explanation
class Solution {
  public:
    string predictPartyVictory(string senate) {
        queue<int> q1, q2;
        int m = senate.length();
        for (int i = 0; i < m; i++) {
            senate[i] == 'R' ? q1.push(i) : q2.push(i);
        }
        while (!q1.empty() && !q2.empty()) {
            int r_index = q1.front(), d_index = q2.front();
            q1.pop(), q2.pop();
            (r_index < d_index) ? q1.push(r_index + m) : q2.push(d_index + m);
        }
        return (q1.size() > q2.size()) ? "Radiant" : "Dire";
    }
};
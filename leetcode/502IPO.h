#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
//自己的第一种解法 这种解法超时
class Solution {
  public:
    int findMaximizedCapital(int k, int W, vector<int> &Profits,
                             vector<int> &Capital) {
        vector<pair<int, int>> dir;
        vector<int> visited(Profits.size(), 0);
        for (int i = 0; i < Profits.size(); i++) {
            dir.emplace_back(Profits[i], i);
        }
        sort(dir.begin(), dir.end(), [](pair<int, int> &a, pair<int, int> &b) {
            return a.first > b.first;
        });
        for (int i = 0; i < k; i++) {
            int j = 0;
            for (; j < dir.size(); j++) {
                if (visited[dir[j].second] == 0 &&
                    Capital[dir[j].second] <= W) {
                    visited[dir[j].second] = 1;
                    W += dir[j].first;
                    break;
                }
            }
            if (j == dir.size()) {
                return W;
            }
        }
        return W;
    }
};

// leetcode的解法 还是很骚的 就是基于暴力解法的改进 用了两个队列
// https://discuss.leetcode.com/topic/77768/very-simple-greedy-java-solution-using-two-priorityqueues?page=1
// https://discuss.leetcode.com/topic/77768/very-simple-greedy-java-solution-using-two-priorityqueues/17?page=1
class Solution_0 {
  public:
    int findMaximizedCapital(int k, int W, vector<int> &Profits,
                             vector<int> &Capital) {
        auto cmpBigger = [](pair<int, int> &a, pair<int, int> &b) {
            return a.first > b.first;
        };
        auto cmpSmaller = [](pair<int, int> &a, pair<int, int> &b) {
            return a.second < b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       decltype(cmpBigger)> minStack(cmpBigger);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       decltype(cmpSmaller)> maxStack(cmpSmaller);
        for (int i = 0; i < Profits.size(); ++i) {
            minStack.push({Capital[i], Profits[i]});
        }
        while (k--) {
            while (minStack.size() && minStack.top().first <= W) {
                maxStack.push(minStack.top());
                minStack.pop();
            }
            if (maxStack.empty()) {
                return W;
            }
            W += maxStack.top().second;
            maxStack.pop();
        }
        return W;
    }
};

// leetcode上 python的解法 和上面的思想是一样的
// https://discuss.leetcode.com/topic/77791/python-solution-by-priority-queue-with-explanation
// https://discuss.leetcode.com/topic/77795/python-solution/14
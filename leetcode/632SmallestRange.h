#include <queue>
#include <vector>
using namespace std;

// 这题没什么好说的 直接看的答案 解法以前碰到过 好题 但是又一次没写出来
// 来自LeetCode的答案
// https://leetcode.com/problems/smallest-range/discuss/104893/Java-Code-using-PriorityQueue.-similar-to-merge-k-array
class Solution {
    class Element {
      public:
        int x;
        int y;
        int val;
        Element(int x, int y, int val) {
            this->x = x;
            this->y = y;
            this->val = val;
        }
        // bool operator<(const Element &a) { return this->val < a.val; }
    };

  public:
    vector<int> smallestRange(vector<vector<int>> &nums) {
        auto comp = [](Element &a, Element &b) { return a.val > b.val; };
        priority_queue<Element, vector<Element>, decltype(comp)> pq(comp);
        int maxValue = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            Element e = Element(i, 0, nums[i][0]);
            pq.push(e);
            maxValue = max(maxValue, nums[i][0]);
        }
        int range = INT_MAX;
        int start = -1, end = -1;
        while (pq.size() == nums.size()) {
            Element curr = pq.top();
            pq.pop();
            if (maxValue - curr.val < range) {
                range = maxValue - curr.val;
                start = curr.val;
                end = maxValue;
            }
            if (curr.y + 1 < nums[curr.x].size()) {
                curr.y++;
                curr.val = nums[curr.x][curr.y];
                pq.push(curr);
                maxValue = max(maxValue, curr.val);
            }
        }
        return {start, end};
    }
};

// 一种更吊的解法 来自LeetCode
// https://leetcode.com/problems/smallest-range/discuss/104886/Clean-C++-priority_queue-solution-using-iterators
class Solution_0 {
  public:
    vector<int> smallestRange(vector<vector<int>> &nums) {
        typedef vector<int>::iterator vi;

        struct comp {
            bool operator()(pair<vi, vi> p1, pair<vi, vi> p2) {
                return *p1.first > *p2.first;
            }
        };
        int lo = INT_MAX, hi = INT_MIN;
        priority_queue<pair<vi, vi>, vector<pair<vi, vi>>, comp> pq;
        for (auto &row : nums) {
            lo = min(lo, row[0]);
            hi = max(hi, row[0]);
            pq.push({row.begin(), row.end()});
        }
        vector<int> ans = {lo, hi};
        while (true) {
            auto p = pq.top();
            pq.pop();
            ++p.first;
            if (p.first == p.second)
                break;
            pq.push(p);

            lo = *pq.top().first;
            hi = max(hi, *p.first);
            if (hi - lo < ans[1] - ans[0])
                ans = {lo, hi};
        }
        return ans;
    }
};
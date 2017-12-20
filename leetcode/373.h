#include <vector>
#include <queue>
#include <set>
using namespace std;
//没有写出来 其实还是非常有难度的
// leetcode的答案
// https://discuss.leetcode.com/topic/50481/clean-16ms-c-o-n-space-o-klogn-time-solution-using-priority-queue
class Solution {
  public:
    vector<pair<int, int>> kSmallestPairs(vector<int> &nums1,
                                          vector<int> &nums2, int k) {
        vector<pair<int, int>> result;
        if (nums1.empty() || nums2.empty() || k <= 0)
            return result;

        auto comp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) {
            return nums1[a.first] + nums2[a.second] >
                   nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)>
            min_heap(comp);
        min_heap.emplace(0, 0);
        while (k-- && min_heap.size()) {
            auto idx_pair = min_heap.top();
            min_heap.pop();
            result.emplace_back(nums1[idx_pair.first], nums2[idx_pair.second]);
            if (idx_pair.first + 1 < nums1.size())
                min_heap.emplace(idx_pair.first + 1, idx_pair.second);
            if (idx_pair.first == 0 && idx_pair.second + 1 < nums2.size())
                min_heap.emplace(idx_pair.first, idx_pair.second + 1);
        }
        return result;
    }
};

////比较容易懂的解法
//其实算法的思想是一样的
// https://discuss.leetcode.com/topic/50885/simple-java-o-klogk-solution-with-explanation?page=1
// https://discuss.leetcode.com/topic/50885/simple-java-o-klogk-solution-with-explanation/13?page=1
// https://discuss.leetcode.com/topic/50481/clean-16ms-c-o-n-space-o-klogn-time-solution-using-priority-queue/19
//通俗易懂的方法
class Solution_0 {
  public:
    vector<pair<int, int>> kSmallestPairs(vector<int> &nums1,
                                          vector<int> &nums2, int k) {
        vector<pair<int, int>> result;
        if (nums1.empty() || nums2.empty() || k <= 0)
            return result;

        auto comp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) {
            return nums1[a.first] + nums2[a.second] >
                   nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)>
            min_heap(comp);
        for (int i = 0; i < nums1.size(); i++)
            min_heap.emplace(i, 0);
        while (k-- && !min_heap.empty()) {
            auto ctop = min_heap.top();
            min_heap.pop();
            result.emplace_back(nums1[ctop.first], nums2[ctop.second]);
            if (ctop.second + 1 < nums2.size())
                min_heap.emplace(ctop.first, ctop.second + 1);
        }
        return result;
    }
};